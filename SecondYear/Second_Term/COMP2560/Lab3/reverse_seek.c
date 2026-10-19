
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef O_BINARY
#define O_BINARY 0
#endif

int main(int argc, char *argv[])
{
    int input_fd;
    int output_fd;
    off_t file_size;
    off_t position;
    char byte;

    if (argc != 3)
    {
        printf("Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], argv[2]) == 0)
    {
        fprintf(stderr, "Input and output files must be different.\n");
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY | O_BINARY);

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

    output_fd = open(
        argv[2],
        O_WRONLY | O_CREAT | O_TRUNC | O_BINARY,
        0644);

    if (output_fd < 0)
    {
        perror("Error opening output file");
        close(input_fd);
        return 1;
    }

    for (position = file_size; position > 0; position--)
    {
        if (lseek(input_fd, position - 1, SEEK_SET) < 0)
        {
            perror("Error moving file position");
            close(input_fd);
            close(output_fd);
            return 1;
        }

        ssize_t bytes_read = read(input_fd, &byte, 1);

        if (bytes_read < 0)
        {
            perror("Error reading input file");
            close(input_fd);
            close(output_fd);
            return 1;
        }

        if (bytes_read == 0)
        {
            fprintf(stderr, "Unexpected end of file\n");
            close(input_fd);
            close(output_fd);
            return 1;
        }

        ssize_t bytes_written = write(output_fd, &byte, 1);

        if (bytes_written < 0)
        {
            perror("Error writing output file");
            close(input_fd);
            close(output_fd);
            return 1;
        }

        if (bytes_written != 1)
        {
            fprintf(stderr, "Error: byte was not written.\n");
            close(input_fd);
            close(output_fd);
            return 1;
        }
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

    return status;
}
