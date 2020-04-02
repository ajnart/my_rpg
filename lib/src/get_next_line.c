/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line.c
*/

#include <unistd.h>
#include <stdlib.h>

char compute(int fd)
{
    static int i = 0;
    static int just_read = 0;
    static char buffer[4096];

    i += 1;
    if (just_read == 0) {
        just_read = read(fd, buffer, 4096);
        i = 0;
    }
    just_read -= 1;
    return (just_read < 0 ? 0 : buffer[i]);
}

char *my_strdup_alloc(char *str, int lenght)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * lenght);

    while (str[i]) {
        new_str[i] = str[i];
        i += 1;
    }
    new_str[i] = '\0';
    free(str);
    return (new_str);
}

char *get_next_line(int fd)
{
    char curr_char;
    int curr_size = 0;
    char *str = malloc(sizeof(char) * (4096 + 1));

    if (str == NULL || fd < 0)
        return (NULL);
    curr_char = compute(fd);
    while (curr_char != '\n' && curr_char != '\0') {
        str[curr_size] = curr_char;
        curr_size += 1;
        curr_char = compute(fd);
        if (curr_size % (4096) == 0) {
            str[curr_size] = '\0';
            str = my_strdup_alloc(str, curr_size + 4096 + 1);
        }
    }
    str[curr_size] = '\0';
    return (curr_char == '\0' && str[0] == '\0' ? NULL : str);
}