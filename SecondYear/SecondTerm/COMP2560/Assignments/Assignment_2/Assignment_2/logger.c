#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#include "alert.h"

int receive_alert(mqd_t mq, AlertMessage *alert)
{
    if (alert == NULL) {
        errno = EINVAL;
        return -1;
    }

    ssize_t bytes_received;
    do {
        bytes_received = mq_receive(mq, (char *)alert, sizeof(*alert), NULL);
    } while (bytes_received == -1 && errno == EINTR);

    if (bytes_received == -1) {
        return -1;
    }

    if ((size_t)bytes_received != sizeof(*alert)) {
        errno = EMSGSIZE;
        return -1;
    }

    return 0;
}

int log_alert(int fd, const AlertMessage *alert)
{
    if (alert == NULL) {
        errno = EINVAL;
        return -1;
    }

    const unsigned char *buffer = (const unsigned char *)alert;
    size_t total_written = 0;

    while (total_written < sizeof(*alert)) {
        ssize_t bytes_written = write(fd, buffer + total_written,
                                      sizeof(*alert) - total_written);
        if (bytes_written == -1) {
            if (errno == EINTR) {
                continue;
            }
            return -1;
        }

        if (bytes_written == 0) {
            errno = EIO;
            return -1;
        }

        total_written += (size_t)bytes_written;
    }

    return 0;
}

int main(void)
{
    mqd_t mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("logger: mq_open (start the detector first)");
        return EXIT_FAILURE;
    }

    struct mq_attr actual_attr;
    if (mq_getattr(mq, &actual_attr) == -1) {
        perror("logger: mq_getattr");
        if (mq_close(mq) == -1) {
            perror("logger: mq_close during cleanup");
        }
        return EXIT_FAILURE;
    }
    if (actual_attr.mq_msgsize != (long)sizeof(AlertMessage)) {
        fprintf(stderr,
                "logger: queue has message size %ld; expected %zu.\n",
                actual_attr.mq_msgsize, sizeof(AlertMessage));
        if (mq_close(mq) == -1) {
            perror("logger: mq_close during cleanup");
        }
        return EXIT_FAILURE;
    }

    int log_fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (log_fd == -1) {
        perror("logger: open log file");
        if (mq_close(mq) == -1) {
            perror("logger: mq_close during cleanup");
        }
        return EXIT_FAILURE;
    }

    int successful_completion = 0;
    int status = EXIT_SUCCESS;

    for (;;) {
        AlertMessage alert;

        if (receive_alert(mq, &alert) == -1) {
            perror("logger: mq_receive");
            status = EXIT_FAILURE;
            break;
        }

        if (alert.message_id == TERMINATION_ID) {
            successful_completion = 1;
            break;
        }

        if (log_alert(log_fd, &alert) == -1) {
            perror("logger: write log record");
            status = EXIT_FAILURE;
            break;
        }
    }

    if (close(log_fd) == -1) {
        perror("logger: close log file");
        status = EXIT_FAILURE;
    }

    if (mq_close(mq) == -1) {
        perror("logger: mq_close");
        status = EXIT_FAILURE;
    }

    /* Remove the queue only after the termination message was received */
    if (successful_completion && mq_unlink(QUEUE_NAME) == -1) {
        perror("logger: mq_unlink");
        status = EXIT_FAILURE;
    }

    return status;
}
