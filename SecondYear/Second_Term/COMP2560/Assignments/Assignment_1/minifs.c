#include "minifs.h"
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#ifndef O_BINARY
#define O_BINARY 0
#endif

#define BUFFER_SIZE 4096
#define DATA_START ((off_t)(sizeof(MiniFSHeader) + MAX_FILES * sizeof(DirectoryEntry)))

static ssize_t write_all(int fd, const void *buf, size_t count)
{
    const char *bytes = buf;
    size_t total_written = 0;

    while (total_written < count)
    {
        ssize_t n = write(fd, bytes + total_written, count - total_written);

        if (n < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            return -1;
        }

        if (n == 0)
        {
            errno = EIO;
            return -1;
        }

        total_written += (size_t)n;
    }

    return (ssize_t)total_written;
}

static ssize_t read_all(int fd, void *buf, size_t count)
{
    char *bytes = buf;
    size_t total_read = 0;

    while (total_read < count)
    {
        ssize_t n = read(fd, bytes + total_read, count - total_read);

        if (n < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            return -1;
        }

        if (n == 0)
        {
            break;
        }

        total_read += (size_t)n;
    }

    return (ssize_t)total_read;
}

static int read_metadata(int fd, MiniFSHeader *header, DirectoryEntry entries[])
{
    ssize_t n;
    int used_count = 0;
    int i;

    if (lseek(fd, 0, SEEK_SET) < 0)
    {
        return -1;
    }

    n = read_all(fd, header, sizeof(*header));
    if (n != (ssize_t)sizeof(*header))
    {
        if (n >= 0)
        {
            errno = EINVAL;
        }
        return -1;
    }

    n = read_all(fd, entries, sizeof(DirectoryEntry) * MAX_FILES);
    if (n != (ssize_t)(sizeof(DirectoryEntry) * MAX_FILES))
    {
        if (n >= 0)
        {
            errno = EINVAL;
        }
        return -1;
    }

    if (memcmp(header->magic, MINIFS_MAGIC, sizeof(MINIFS_MAGIC)) != 0 ||
        header->num_files < 0 || header->num_files > MAX_FILES)
    {
        errno = EINVAL;
        return -1;
    }

    for (i = 0; i < MAX_FILES; i++)
    {
        if (entries[i].used == 1)
        {
            used_count++;

            if (memchr(entries[i].filename, '\0', MAX_FILENAME) == NULL ||
                entries[i].size < 0 || entries[i].offset < DATA_START)
            {
                errno = EINVAL;
                return -1;
            }
        }
        else if (entries[i].used != 0)
        {
            errno = EINVAL;
            return -1;
        }
    }

    if (used_count != header->num_files)
    {
        errno = EINVAL;
        return -1;
    }

    return 0;
}

int minifs_create(const char *image)
{
    int fd;
    int result = -1;
    MiniFSHeader header;
    DirectoryEntry entries[MAX_FILES];

    fd = open(image, O_CREAT | O_TRUNC | O_RDWR | O_BINARY, 0644);
    if (fd < 0)
    {
        perror("Could not create MiniFS image");
        return -1;
    }

    memset(&header, 0, sizeof(header));
    memcpy(header.magic, MINIFS_MAGIC, sizeof(MINIFS_MAGIC));
    header.num_files = 0;
    memset(entries, 0, sizeof(entries));

    if (write_all(fd, &header, sizeof(header)) < 0)
    {
        perror("Could not write MiniFS header");
        goto cleanup;
    }

    if (write_all(fd, entries, sizeof(entries)) < 0)
    {
        perror("Could not write MiniFS directory");
        goto cleanup;
    }

    result = 0;

cleanup:
    if (close(fd) < 0)
    {
        perror("Could not close MiniFS image");
        result = -1;
    }

    if (result == 0)
    {
        printf("MiniFS image created: %s\n", image);
    }

    return result;
}

int minifs_list(const char *image)
{
    int fd;
    int result = -1;
    int i;
    MiniFSHeader header;
    DirectoryEntry entries[MAX_FILES];

    fd = open(image, O_RDONLY | O_BINARY);
    if (fd < 0)
    {
        perror("Could not open MiniFS image");
        return -1;
    }

    if (read_metadata(fd, &header, entries) < 0)
    {
        perror("Could not read MiniFS metadata");
        goto cleanup;
    }

    printf("%-32s %10s %10s\n", "Filename", "Size", "Offset");
    printf("--------------------------------------------------------------\n");

    for (i = 0; i < MAX_FILES; i++)
    {
        if (entries[i].used == 1)
        {
            printf("%-32s %10d %10d\n",
                   entries[i].filename,
                   entries[i].size,
                   entries[i].offset);
        }
    }

    result = 0;

cleanup:
    if (close(fd) < 0)
    {
        perror("Could not close MiniFS image");
        result = -1;
    }

    return result;
}

int minifs_add(const char *image, const char *source)
{
    int source_fd = -1;
    int image_fd = -1;
    int result = -1;
    int slot = -1;
    int i;
    off_t source_size;
    off_t data_offset;
    off_t remaining;
    const char *stored_name;
    size_t name_length;
    char buffer[BUFFER_SIZE];
    MiniFSHeader header;
    DirectoryEntry entries[MAX_FILES];

    if (strcmp(image, source) == 0)
    {
        fprintf(stderr, "The source file and MiniFS image must be different.\n");
        return -1;
    }

    stored_name = strrchr(source, '/');
    if (stored_name == NULL)
    {
        stored_name = strrchr(source, '\\');
    }
    if (stored_name != NULL)
    {
        stored_name++;
    }
    else
    {
        stored_name = source;
    }

    name_length = strlen(stored_name);
    if (name_length == 0 || name_length >= MAX_FILENAME)
    {
        fprintf(stderr, "Filename is empty or too long (maximum %d characters).\n",
                MAX_FILENAME - 1);
        return -1;
    }

    source_fd = open(source, O_RDONLY | O_BINARY);
    if (source_fd < 0)
    {
        perror("Could not open source file");
        goto cleanup;
    }

    source_size = lseek(source_fd, 0, SEEK_END);
    if (source_size < 0)
    {
        perror("Could not determine source file size");
        goto cleanup;
    }

    if (source_size > INT32_MAX)
    {
        fprintf(stderr, "Source file is too large for MiniFS.\n");
        goto cleanup;
    }

    if (lseek(source_fd, 0, SEEK_SET) < 0)
    {
        perror("Could not return to start of source file");
        goto cleanup;
    }

    image_fd = open(image, O_RDWR | O_BINARY);
    if (image_fd < 0)
    {
        perror("Could not open MiniFS image");
        goto cleanup;
    }

    if (read_metadata(image_fd, &header, entries) < 0)
    {
        perror("Could not read MiniFS metadata");
        goto cleanup;
    }

    for (i = 0; i < MAX_FILES; i++)
    {
        if (entries[i].used == 1 && strcmp(entries[i].filename, stored_name) == 0)
        {
            fprintf(stderr, "A file with that name already exists in MiniFS.\n");
            goto cleanup;
        }
        if (entries[i].used == 0 && slot == -1)
        {
            slot = i;
        }
    }

    if (slot == -1 || header.num_files >= MAX_FILES)
    {
        fprintf(stderr, "MiniFS directory is full.\n");
        goto cleanup;
    }

    data_offset = lseek(image_fd, 0, SEEK_END);
    if (data_offset < 0)
    {
        perror("Could not find end of MiniFS image");
        goto cleanup;
    }

    if (data_offset < DATA_START || data_offset > INT32_MAX ||
        source_size > (off_t)INT32_MAX - data_offset)
    {
        fprintf(stderr, "MiniFS image would exceed its supported size.\n");
        goto cleanup;
    }

    remaining = source_size;
    while (remaining > 0)
    {
        size_t request = sizeof(buffer);
        ssize_t bytes_read;

        if (remaining < (off_t)request)
        {
            request = (size_t)remaining;
        }

        bytes_read = read(source_fd, buffer, request);
        if (bytes_read < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            perror("Could not read source file");
            goto cleanup;
        }

        if (bytes_read == 0)
        {
            fprintf(stderr, "Source file ended earlier than expected.\n");
            goto cleanup;
        }

        if (write_all(image_fd, buffer, (size_t)bytes_read) < 0)
        {
            perror("Could not write file data to MiniFS image");
            goto cleanup;
        }

        remaining -= (off_t)bytes_read;
    }

    memset(&entries[slot], 0, sizeof(entries[slot]));
    memcpy(entries[slot].filename, stored_name, name_length + 1);
    entries[slot].size = (int32_t)source_size;
    entries[slot].offset = (int32_t)data_offset;
    entries[slot].used = 1;
    header.num_files++;

    if (lseek(image_fd, 0, SEEK_SET) < 0)
    {
        perror("Could not seek to MiniFS metadata");
        goto cleanup;
    }

    if (write_all(image_fd, &header, sizeof(header)) < 0 ||
        write_all(image_fd, entries, sizeof(entries)) < 0)
    {
        perror("Could not update MiniFS metadata");
        goto cleanup;
    }

    result = 0;

cleanup:
    if (source_fd >= 0 && close(source_fd) < 0)
    {
        perror("Could not close source file");
        result = -1;
    }
    if (image_fd >= 0 && close(image_fd) < 0)
    {
        perror("Could not close MiniFS image");
        result = -1;
    }

    if (result == 0)
    {
        printf("Added %s (%lld bytes)\n", stored_name, (long long)source_size);
    }

    return result;
}

int minifs_extract(const char *image, const char *name, const char *destination)
{
    int image_fd = -1;
    int destination_fd = -1;
    int result = -1;
    int i;
    DirectoryEntry found_entry;
    int found = 0;
    off_t remaining;
    char buffer[BUFFER_SIZE];
    MiniFSHeader header;
    DirectoryEntry entries[MAX_FILES];

    if (strcmp(image, destination) == 0)
    {
        fprintf(stderr, "The destination must not be the MiniFS image itself.\n");
        return -1;
    }

    image_fd = open(image, O_RDONLY | O_BINARY);
    if (image_fd < 0)
    {
        perror("Could not open MiniFS image");
        goto cleanup;
    }

    if (read_metadata(image_fd, &header, entries) < 0)
    {
        perror("Could not read MiniFS metadata");
        goto cleanup;
    }

    for (i = 0; i < MAX_FILES; i++)
    {
        if (entries[i].used == 1 && strcmp(entries[i].filename, name) == 0)
        {
            found_entry = entries[i];
            found = 1;
            break;
        }
    }

    if (!found)
    {
        fprintf(stderr, "File not found in MiniFS: %s\n", name);
        goto cleanup;
    }

    if (lseek(image_fd, found_entry.offset, SEEK_SET) < 0)
    {
        perror("Could not seek to stored file data");
        goto cleanup;
    }

    destination_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644);
    if (destination_fd < 0)
    {
        perror("Could not open destination file");
        goto cleanup;
    }

    remaining = found_entry.size;
    while (remaining > 0)
    {
        size_t request = sizeof(buffer);
        ssize_t bytes_read;

        if (remaining < (off_t)request)
        {
            request = (size_t)remaining;
        }

        bytes_read = read(image_fd, buffer, request);
        if (bytes_read < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            perror("Could not read stored file data");
            goto cleanup;
        }

        if (bytes_read == 0)
        {
            fprintf(stderr, "MiniFS data ended earlier than expected.\n");
            goto cleanup;
        }

        if (write_all(destination_fd, buffer, (size_t)bytes_read) < 0)
        {
            perror("Could not write destination file");
            goto cleanup;
        }

        remaining -= (off_t)bytes_read;
    }

    result = 0;

cleanup:
    if (image_fd >= 0 && close(image_fd) < 0)
    {
        perror("Could not close MiniFS image");
        result = -1;
    }
    if (destination_fd >= 0 && close(destination_fd) < 0)
    {
        perror("Could not close destination file");
        result = -1;
    }

    if (result == 0)
    {
        printf("Extracted %s to %s\n", name, destination);
    }

    return result;
}

static void usage(const char *prog)
{
    fprintf(stderr,
            "Usage:\n"
            "  %s create <image>\n"
            "  %s list <image>\n"
            "  %s add <image> <source-file>\n"
            "  %s extract <image> <stored-name> <destination>\n",
            prog, prog, prog, prog);
}

int main(int argc, char *argv[])
{
    int rc = -1;

    if (argc < 3)
    {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "create") == 0 && argc == 3)
    {
        rc = minifs_create(argv[2]);
    }
    else if (strcmp(argv[1], "list") == 0 && argc == 3)
    {
        rc = minifs_list(argv[2]);
    }
    else if (strcmp(argv[1], "add") == 0 && argc == 4)
    {
        rc = minifs_add(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "extract") == 0 && argc == 5)
    {
        rc = minifs_extract(argv[2], argv[3], argv[4]);
    }
    else
    {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    return rc == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
