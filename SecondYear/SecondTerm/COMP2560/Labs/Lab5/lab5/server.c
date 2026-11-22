#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_CLIENT_TO_SERVER "/tmp/fifo_client_to_server"
#define FIFO_SERVER_TO_CLIENT "/tmp/fifo_server_to_client"

/* Returns 1 if created by this process, 0 if already present, -1 on error. */
static int ensure_fifo(const char *path)
{
    struct stat st;

    if (mkfifo(path, 0666) == 0) {
        return 1;
    }
    if (errno != EEXIST) {
        perror("mkfifo");
        return -1;
    }
    if (lstat(path, &st) == -1) {
        perror("lstat");
        return -1;
    }
    if (!S_ISFIFO(st.st_mode)) {
        fprintf(stderr, "%s exists but is not a FIFO\n", path);
        return -1;
    }
    return 0;
}

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

static void remove_fifo_if_created(const char *path, int created)
{
    if (created && unlink(path) == -1 && errno != ENOENT) {
        perror("unlink FIFO");
    }
}

int main(void)
{
    int created_request_fifo;
    int created_reply_fifo;
    int request_fd = -1;
    int reply_fd = -1;
    FILE *request_stream = NULL;
    char *request = NULL;
    size_t request_capacity = 0;
    char *server_reply = NULL;
    size_t reply_capacity = 0;
    int result = EXIT_SUCCESS;

    /* Convert a broken-pipe write into an EPIPE error we can handle. */
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
        perror("signal");
        return EXIT_FAILURE;
    }

    created_request_fifo = ensure_fifo(FIFO_CLIENT_TO_SERVER);
    if (created_request_fifo == -1) {
        return EXIT_FAILURE;
    }
    created_reply_fifo = ensure_fifo(FIFO_SERVER_TO_CLIENT);
    if (created_reply_fifo == -1) {
        remove_fifo_if_created(FIFO_CLIENT_TO_SERVER, created_request_fifo);
        return EXIT_FAILURE;
    }

    printf("Server ready. Waiting for client...\n");

    /*
     * Open order prevents the read/read deadlock:
     * server reads client->server; client writes client->server;
     * then server writes server->client; client reads server->client.
     */
    request_fd = open(FIFO_CLIENT_TO_SERVER, O_RDONLY);
    if (request_fd == -1) {
        perror("open client-to-server FIFO");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    reply_fd = open(FIFO_SERVER_TO_CLIENT, O_WRONLY);
    if (reply_fd == -1) {
        perror("open server-to-client FIFO");
        result = EXIT_FAILURE;
        goto cleanup;
    }

    request_stream = fdopen(request_fd, "r");
    if (request_stream == NULL) {
        perror("fdopen request FIFO");
        result = EXIT_FAILURE;
        goto cleanup;
    }
    request_fd = -1; /* request_stream now owns this descriptor. */

    for (;;) {
        ssize_t request_length = getline(&request, &request_capacity, request_stream);
        int quitting;
        ssize_t reply_length;

        if (request_length == -1) {
            if (ferror(request_stream)) {
                perror("read request FIFO");
                result = EXIT_FAILURE;
            } else {
                fprintf(stderr, "Client disconnected (end-of-file).\n");
            }
            break;
        }

        printf("Client: %s", request);
        if (request[request_length - 1] != '\n') {
            putchar('\n');
        }

        quitting = is_exit_message(request);
        if (quitting) {
            static const char goodbye[] = "Goodbye!\n";
            if (write_all(reply_fd, goodbye, sizeof(goodbye) - 1) == -1) {
                perror("write reply (client may have disconnected)");
                result = EXIT_FAILURE;
            }
            break;
        }

        printf("Reply: ");
        fflush(stdout);
        reply_length = getline(&server_reply, &reply_capacity, stdin);
        if (reply_length == -1) {
            static const char closing[] = "Server closing.\n";
            if (write_all(reply_fd, closing, sizeof(closing) - 1) == -1) {
                perror("write closing reply");
                result = EXIT_FAILURE;
            }
            break;
        }

        if (reply_length == 0 || server_reply[reply_length - 1] != '\n') {
            char *larger = realloc(server_reply, (size_t)reply_length + 2);
            if (larger == NULL) {
                perror("realloc");
                result = EXIT_FAILURE;
                break;
            }
            server_reply = larger;
            reply_capacity = (size_t)reply_length + 2;
            server_reply[reply_length++] = '\n';
            server_reply[reply_length] = '\0';
        }

        if (write_all(reply_fd, server_reply, (size_t)reply_length) == -1) {
            perror("write reply (client may have disconnected)");
            result = EXIT_FAILURE;
            break;
        }
    }

cleanup:
    free(request);
    free(server_reply);
    if (request_stream != NULL) {
        if (fclose(request_stream) == EOF) {
            perror("fclose request FIFO");
            result = EXIT_FAILURE;
        }
    } else if (request_fd != -1) {
        if (close(request_fd) == -1) {
            perror("close request FIFO");
            result = EXIT_FAILURE;
        }
    }
    if (reply_fd != -1 && close(reply_fd) == -1) {
        perror("close reply FIFO");
        result = EXIT_FAILURE;
    }

    /* The server creates and therefore owns cleanup of these two FIFO paths. */
    remove_fifo_if_created(FIFO_CLIENT_TO_SERVER, created_request_fifo);
    remove_fifo_if_created(FIFO_SERVER_TO_CLIENT, created_reply_fifo);
    return result;
}
