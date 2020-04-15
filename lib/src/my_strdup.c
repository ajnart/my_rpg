/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** my_strdup.c
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

char *my_strcpy(char *dest, char *src)
{
    return (my_strncpy(dest, src, my_strlen(src)));
}

char *my_strndup(char *str, int n)
{
    char *dest = malloc(n + 1);
    my_strncpy(dest, str, n);
    return dest;
}

char *my_strdup(char *str)
{
    return (my_strndup(str, my_strlen(str)));
}
