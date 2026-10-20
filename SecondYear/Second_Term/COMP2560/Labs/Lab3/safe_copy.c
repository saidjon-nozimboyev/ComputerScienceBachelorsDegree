#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 64

int main(void)
{
    int input_fd;
    int output_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    input_fd = open("input.txt", O_RDONLY);

    if (input_fd < 0)
    {
        perror("Error opening input.txt");
        return 1;
    }

    output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (output_fd < 0)
    {
        perror("Error opening output.txt");

        if (close(input_fd) < 0)
        {
            perror("Error closing input.txt");
        }

        return 1;
    }

    while ((bytes_read = read(input_fd, buffer, sizeof(buffer))) > 0)
    {
        ssize_t total_written = 0;

        while (total_written < bytes_read)
        {
            ssize_t bytes_written = write(
                output_fd,
                buffer + total_written,
                (size_t)(bytes_read - total_written));

            if (bytes_written < 0)
            {
                perror("Error writing output.txt");

                if (close(input_fd) < 0)
                {
                    perror("Error closing input.txt");
                }

                if (close(output_fd) < 0)
                {
                    perror("Error closing output.txt");
                }

                return 1;
            }

            if (bytes_written == 0)
            {
                fprintf(stderr, "Error: no bytes were written.\n");

                if (close(input_fd) < 0)
                {
                    perror("Error closing input.txt");
                }

                if (close(output_fd) < 0)
                {
                    perror("Error closing output.txt");
                }

                return 1;
            }

            total_written += bytes_written;
        }
    }

    if (bytes_read < 0)
    {
        perror("Error reading input.txt");

        if (close(input_fd) < 0)
        {
            perror("Error closing input.txt");
        }

        if (close(output_fd) < 0)
        {
            perror("Error closing output.txt");
        }

        return 1;
    }

    int status = 0;

    if (close(input_fd) < 0)
    {
        perror("Error closing input.txt");
        status = 1;
    }

    if (close(output_fd) < 0)
    {
        perror("Error closing output.txt");
        status = 1;
    }

    return status;
}