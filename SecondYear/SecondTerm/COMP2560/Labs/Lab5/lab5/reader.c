#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/comp2560_lab5_nozimbo_fifo"

static int run_once(void)
{
    char buffer[100];
    size_t used = 0;
    int fd = open(FIFO_PATH, O_RDONLY);

    if (fd == -1) {
        perror("open FIFO for reading");
        return EXIT_FAILURE;
    }

    /* Read until the writer closes, always reserving one byte for '\0'. */
    while (used < sizeof(buffer) - 1) {
        ssize_t n = read(fd, buffer + used, sizeof(buffer) - 1 - used);
        if (n == -1) {
            if (errno == EINTR) {
                continue;
            }
            perror("read");
            (void)close(fd);
            return EXIT_FAILURE;
        }
        if (n == 0) {
            break;
        }
        used += (size_t)n;
    }

    buffer[used] = '\0';
    printf("Received: %s\n", buffer);

    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int run_interactive(void)
{
    int fd = open(FIFO_PATH, O_RDONLY);
    FILE *stream;
    char *line = NULL;
    size_t capacity = 0;
    int result = EXIT_SUCCESS;

    if (fd == -1) {
        perror("open FIFO for reading");
        return EXIT_FAILURE;
    }

    stream = fdopen(fd, "r");
    if (stream == NULL) {
        perror("fdopen");
        (void)close(fd);
        return EXIT_FAILURE;
    }

    printf("Connected to writer. Waiting for messages...\n");
    for (;;) {
        ssize_t length = getline(&line, &capacity, stream);
        if (length == -1) {
            if (ferror(stream)) {
                perror("read from FIFO");
                result = EXIT_FAILURE;
            } else {
                printf("Writer closed the pipe.\n");
            }
            break;
        }

        printf("Received: %s", line);
        if (line[length - 1] != '\n') {
            putchar('\n');
        }

        if (strcmp(line, "exit\n") == 0 || strcmp(line, "exit\r\n") == 0) {
            break;
        }
    }

    free(line);
    if (fclose(stream) == EOF) {
        perror("fclose");
        result = EXIT_FAILURE;
    }
    return result;
}

int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "--once") == 0) {
        return run_once();
    }
    if (argc != 1) {
        fprintf(stderr, "Usage: %s [--once]\n", argv[0]);
        return EXIT_FAILURE;
    }
    return run_interactive();
}
