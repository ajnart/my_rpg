/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** str_str.c
*/

#include <stdlib.h>

char *my_strcat(char *str1, char *str2);

char *my_strstr(char *str, char *sub)
{
    int index = 0;
    int checki = 0;

    while (str[index]) {
        if (str[index + checki] == sub[checki]) {
            checki++;
        } else if (!sub[checki]) {
            return (str + index);
        } else {
            checki = 0;
            ++index;
        }
    }
    return (0);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int length = 0;
    int i = 0;

    if (!src || !dest) {
        return NULL;
    }
    for (length = 0; dest[length] != '\0'; ++length);
    if (nb < 0) {
        for (nb = 0; src[nb] != '\0'; ++nb);
    }
    while (src[i] != '\0' && i != nb) {
        dest[length + i] = src[i];
        ++i;
    }
    dest[length + i] = '\0';
    return (dest);
}

void str_append(char **src, char *add)
{
    char *ret;

    ret = my_strcat(*src, add);
    free(*src);
    *src = ret;
}

int my_str_isalpha(char *str)
{
    int i = 0;

    while (str[i])
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z'))
            i += 1;
        else
        {
            return (1);
        }
    }
    return (0);
}