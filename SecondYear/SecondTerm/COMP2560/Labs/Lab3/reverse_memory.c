
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int input_fd;
    int output_fd;
    off_t file_size;
    char *buffer = NULL;
    size_t size;
    size_t total_read = 0;
    size_t total_written = 0;

    if (argc != 3)
    {
        printf("Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY);

    if (input_fd < 0)
    {
        perror("Error opening input file");
        return 1;
    }

    file_size = lseek(input_fd, 0, SEEK_END);

    if (file_size < 0)
    {
        perror("Error getting file size");
        close(input_fd);
        return 1;
    }

    if (lseek(input_fd, 0, SEEK_SET) < 0)
    {
        perror("Error moving to beginning of file");
        close(input_fd);
        return 1;
    }

    size = (size_t)file_size;

    if (size > 0)
    {
        buffer = malloc(size);

        if (buffer == NULL)
        {
            perror("Error allocating memory");
            close(input_fd);
            return 1;
        }

        while (total_read < size)
        {
            ssize_t bytes_read = read(
                input_fd,
                buffer + total_read,
                size - total_read);

            if (bytes_read < 0)
            {
                perror("Error reading input file");
                free(buffer);
                close(input_fd);
                return 1;
            }

            if (bytes_read == 0)
            {
                fprintf(stderr, "Unexpected end of file\n");
                free(buffer);
                close(input_fd);
                return 1;
            }

            total_read += (size_t)bytes_read;
        }

        size_t left = 0;
        size_t right = size - 1;

        while (left < right)
        {
            char temp = buffer[left];
            buffer[left] = buffer[right];
            buffer[right] = temp;

            left++;
            right--;
        }
    }

    output_fd = open(
        argv[2],
        O_WRONLY | O_CREAT | O_TRUNC,
        0644);

    if (output_fd < 0)
    {
        perror("Error opening output file");
        free(buffer);
        close(input_fd);
        return 1;
    }

    while (total_written < size)
    {
        ssize_t bytes_written = write(
            output_fd,
            buffer + total_written,
            size - total_written);

        if (bytes_written < 0)
        {
            perror("Error writing output file");
            free(buffer);
            close(input_fd);
            close(output_fd);
            return 1;
        }

        if (bytes_written == 0)
        {
            fprintf(stderr, "No bytes were written\n");
            free(buffer);
            close(input_fd);
            close(output_fd);
            return 1;
        }

        total_written += (size_t)bytes_written;
    }

    int status = 0;

    if (close(input_fd) < 0)
    {
        perror("Error closing input file");
        status = 1;
    }

    if (close(output_fd) < 0)
    {
        perror("Error closing output file");
        status = 1;
    }

    free(buffer);

    return status;
}
