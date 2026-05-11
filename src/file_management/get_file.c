/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** corewar
*/

#include "../../include/header.h"

static char *read_file_content(int fd, int size)
{
    ssize_t rd = 0;
    char *str = malloc(size + 1);

    if (!str)
        return NULL;
    rd = read(fd, str, size);
    if (rd != size) {
        free(str);
        return NULL;
    }
    str[size] = '\0';
    return str;
}

char *get_file(const char *filename)
{
    int fd = 0;
    struct stat sb;
    char *str = NULL;

    if (stat(filename, &sb) == -1)
        return NULL;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return NULL;
    str = read_file_content(fd, sb.st_size);
    close(fd);
    return str;
}
