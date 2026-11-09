#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/comp2560_lab5_nozimbo_fifo"

/* Returns 1 if this process created the FIFO, 0 if it already existed. */
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

static void remove_fifo_if_created(int created)
{
    if (created && unlink(FIFO_PATH) == -1 && errno != ENOENT) {
        perror("unlink");
    }
}

static int run_once(int fifo_created)
{
    static const char message[] = "Hello from writer!";
    int fd = open(FIFO_PATH, O_WRONLY);

    if (fd == -1) {
        perror("open FIFO for writing");
        remove_fifo_if_created(fifo_created);
        return EXIT_FAILURE;
    }

    if (write_all(fd, message, sizeof(message) - 1) == -1) {
        perror("write");
        (void)close(fd);
        remove_fifo_if_created(fifo_created);
        return EXIT_FAILURE;
    }

    if (close(fd) == -1) {
        perror("close");
        remove_fifo_if_created(fifo_created);
        return EXIT_FAILURE;
    }

    remove_fifo_if_created(fifo_created);
    return EXIT_SUCCESS;
}

static int run_interactive(int fifo_created)
{
    int fd = open(FIFO_PATH, O_WRONLY);
    char *line = NULL;
    size_t capacity = 0;
    int result = EXIT_SUCCESS;

    if (fd == -1) {
        perror("open FIFO for writing");
        remove_fifo_if_created(fifo_created);
        return EXIT_FAILURE;
    }

    printf("Connected to reader. Type messages; enter 'exit' to quit.\n");
    for (;;) {
        ssize_t length;
        size_t message_length;
        int is_exit;

        printf("Enter message: ");
        fflush(stdout);

        length = getline(&line, &capacity, stdin);
        if (length == -1) {
            if (ferror(stdin)) {
                perror("getline");
                result = EXIT_FAILURE;
            }
            break;
        }

        message_length = (size_t)length;
        if (message_length == 0 || line[message_length - 1] != '\n') {
            char *larger = realloc(line, message_length + 2);
            if (larger == NULL) {
                perror("realloc");
                result = EXIT_FAILURE;
                break;
            }
            line = larger;
            capacity = message_length + 2;
            line[message_length++] = '\n';
            line[message_length] = '\0';
        }

        is_exit = (strcmp(line, "exit\n") == 0 || strcmp(line, "exit\r\n") == 0);
        if (write_all(fd, line, message_length) == -1) {
            perror("write");
            result = EXIT_FAILURE;
            break;
        }

        if (is_exit) {
            break;
        }
    }

    free(line);
    if (close(fd) == -1) {
        perror("close");
        result = EXIT_FAILURE;
    }
    remove_fifo_if_created(fifo_created);
    return result;
}

int main(int argc, char *argv[])
{
    int fifo_created;
    int once = 0;

    if (argc == 2 && strcmp(argv[1], "--once") == 0) {
        once = 1;
    } else if (argc != 1) {
        fprintf(stderr, "Usage: %s [--once]\n", argv[0]);
        return EXIT_FAILURE;
    }

    fifo_created = ensure_fifo(FIFO_PATH);
    if (fifo_created == -1) {
        return EXIT_FAILURE;
    }

    return once ? run_once(fifo_created) : run_interactive(fifo_created);
}
