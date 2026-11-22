#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FIFO_CLIENT_TO_SERVER "/tmp/fifo_client_to_server"
#define FIFO_SERVER_TO_CLIENT "/tmp/fifo_server_to_client"

static int write_all(int fd, const void *data, size_t length)
{
    const char *cursor = data;
    size_t written = 0;

    while (written < length) {
        ssize_t n = write(fd, cursor + written, length - written);
        if (n == -1) {
            if (errno == EINTR) {
                continue;
            }
            return -1;
        }
        if (n == 0) {
            errno = EIO;
            return -1;
        }
        written += (size_t)n;
    }

    return 0;
}

static int is_exit_message(const char *line)
{
    return strcmp(line, "exit\n") == 0 || strcmp(line, "exit\r\n") == 0 ||
           strcmp(line, "exit") == 0;
}

int main(void)
{
    int request_fd = -1;
    int reply_fd = -1;
    FILE *reply_stream = NULL;
    char *input = NULL;
    size_t input_capacity = 0;
    char *reply = NULL;
    size_t reply_capacity = 0;
    int result = EXIT_SUCCESS;

    /* Avoid process termination if the server closes its read end. */
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
        perror("signal");
        return EXIT_FAILURE;
    }

    /* Open order pairs with the server: client writes requests first. */
    request_fd = open(FIFO_CLIENT_TO_SERVER, O_WRONLY);
    if (request_fd == -1) {
        perror("open client-to-server FIFO");
        return EXIT_FAILURE;
    }

    reply_fd = open(FIFO_SERVER_TO_CLIENT, O_RDONLY);
    if (reply_fd == -1) {
        perror("open server-to-client FIFO");
        (void)close(request_fd);
        return EXIT_FAILURE;
    }

    reply_stream = fdopen(reply_fd, "r");
    if (reply_stream == NULL) {
        perror("fdopen reply FIFO");
        (void)close(reply_fd);
        (void)close(request_fd);
        return EXIT_FAILURE;
    }

    printf("Connected to server. Type 'exit' to finish.\n");
    for (;;) {
        ssize_t input_length;
        int quitting;

        printf("You: ");
        fflush(stdout);
        input_length = getline(&input, &input_capacity, stdin);
        if (input_length == -1) {
            if (ferror(stdin)) {
                perror("getline from stdin");
                result = EXIT_FAILURE;
            }
            break;
        }

        if (input_length == 0 || input[input_length - 1] != '\n') {
            char *larger = realloc(input, (size_t)input_length + 2);
            if (larger == NULL) {
                perror("realloc");
                result = EXIT_FAILURE;
                break;
            }
            input = larger;
            input_capacity = (size_t)input_length + 2;
            input[input_length++] = '\n';
            input[input_length] = '\0';
        }

        quitting = is_exit_message(input);
        if (write_all(request_fd, input, (size_t)input_length) == -1) {
            perror("write request (the server may have disconnected)");
            result = EXIT_FAILURE;
            break;
        }

        {
            ssize_t reply_length = getline(&reply, &reply_capacity, reply_stream);
            if (reply_length == -1) {
                if (ferror(reply_stream)) {
                    perror("read reply");
                    result = EXIT_FAILURE;
                } else {
                    fprintf(stderr, "Server disconnected before replying.\n");
                    result = EXIT_FAILURE;
                }
                break;
            }
            printf("Server: %s", reply);
            if (reply[reply_length - 1] != '\n') {
                putchar('\n');
            }
        }

        if (quitting) {
            break;
        }
    }

    free(input);
    free(reply);
    if (fclose(reply_stream) == EOF) {
        perror("fclose reply FIFO");
        result = EXIT_FAILURE;
    }
    if (close(request_fd) == -1) {
        perror("close request FIFO");
        result = EXIT_FAILURE;
    }
    return result;
}
