/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** str_str.c
*/

#include <stdlib.h>

char *my_strcat(char *str1, char *str2);

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