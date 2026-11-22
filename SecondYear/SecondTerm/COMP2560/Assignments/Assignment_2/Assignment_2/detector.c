#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#include "alert.h"

/* Sample alerts are intentionally mixed by priority */
static const AlertMessage alerts[ALERT_COUNT] = {
    {1, "Repeated failed login attempts", AUTH_SERVER, LOW, AUDIT},
    {2, "SQL injection attempt", DATABASE_SERVER, HIGH, BLOCK},
    {3, "Unusual outgoing traffic", WEB_SERVER, MEDIUM, REPORT},
    {4, "Suspicious payment request", PAYMENT_GATEWAY, HIGH, ISOLATE},
    {5, "Unrecognized email attachment", EMAIL_SERVER, LOW, REPORT},
    {6, "Abnormal database query volume", DATABASE_SERVER, MEDIUM, AUDIT},
    {7, "Credential stuffing detected", AUTH_SERVER, HIGH, BLOCK},
    {8, "Unexpected web service restart", WEB_SERVER, LOW, AUDIT},
    {9, "Potential payment fraud", PAYMENT_GATEWAY, MEDIUM, REPORT},
    {10, "Malicious email link", EMAIL_SERVER, HIGH, BLOCK},
    {11, "Unusual administrator login", AUTH_SERVER, MEDIUM, ISOLATE},
    {12, "Web server configuration change", WEB_SERVER, LOW, AUDIT}
};

/*
 * Linux commonly permits at most 10 messages per queue by default
 * If the system is configured with a smaller limit, try a smaller queue
 * The queue can still carry all alerts over time because mq_send() blocks
 * when the queue is full until the logger receives a message
 */
static mqd_t create_alert_queue(void)
{
    struct mq_attr attr = {0};
    attr.mq_flags = 0;
    attr.mq_msgsize = (long)sizeof(AlertMessage);

    for (long max_messages = 10; max_messages >= 1; --max_messages) {
        attr.mq_maxmsg = max_messages;
        mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0660, &attr);
        if (mq != (mqd_t)-1) {
            return mq;
        }

        /* EINVAL may mean that this mq_maxmsg exceeds the system limit */
        if (errno != EINVAL) {
            return (mqd_t)-1;
        }
    }

    return (mqd_t)-1;
}

int send_alert(mqd_t mq, const AlertMessage *alert)
{
    if (alert == NULL) {
        errno = EINVAL;
        return -1;
    }

    while (mq_send(mq, (const char *)alert, sizeof(*alert),
                   (unsigned int)alert->priority) == -1) {
        if (errno != EINTR) {
            return -1;
        }
    }

    return 0;
}

int main(void)
{
    mqd_t mq = create_alert_queue();
    if (mq == (mqd_t)-1) {
        perror("detector: mq_open");
        return EXIT_FAILURE;
    }

    /* Verify that an existing queue has the message size this program uses */
    struct mq_attr actual_attr;
    if (mq_getattr(mq, &actual_attr) == -1) {
        perror("detector: mq_getattr");
        if (mq_close(mq) == -1) {
            perror("detector: mq_close during cleanup");
        }
        return EXIT_FAILURE;
    }
    if (actual_attr.mq_msgsize != (long)sizeof(AlertMessage)) {
        fprintf(stderr,
                "detector: queue has message size %ld; expected %zu. "
                "Remove the stale queue and try again.\n",
                actual_attr.mq_msgsize, sizeof(AlertMessage));
        if (mq_close(mq) == -1) {
            perror("detector: mq_close during cleanup");
        }
        return EXIT_FAILURE;
    }

    /* Send alerts in the supplied array order; do not sort them */
    for (int i = 0; i < ALERT_COUNT; ++i) {
        if (send_alert(mq, &alerts[i]) == -1) {
            perror("detector: mq_send alert");
            if (mq_close(mq) == -1) {
                perror("detector: mq_close during cleanup");
            }
            return EXIT_FAILURE;
        }
    }

    /* The sentinel is sent last and uses queue priority 0, below all alerts */
    AlertMessage termination = {0};
    termination.message_id = TERMINATION_ID;
    int send_result;
    do {
        send_result = mq_send(mq, (const char *)&termination,
                              sizeof(termination), 0);
    } while (send_result == -1 && errno == EINTR);

    if (send_result == -1) {
        perror("detector: mq_send termination message");
        if (mq_close(mq) == -1) {
            perror("detector: mq_close during cleanup");
        }
        return EXIT_FAILURE;
    }

    if (mq_close(mq) == -1) {
        perror("detector: mq_close");
        return EXIT_FAILURE;
    }

    /* The logger owns queue removal after it processes the sentinel */
    return EXIT_SUCCESS;
}
