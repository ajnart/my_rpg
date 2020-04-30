/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_sprintf.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "../../include/lib.h"

int add_int_to_str(char *buffer, int to_add)
{
    char *number_str = malloc(sizeof(char) * 12);
    my_itoa(to_add, number_str, 10);
    int len = 0;

    if (!number_str)
        return (0);
    my_strcpy(buffer, number_str);
    len = my_strlen(number_str);
    free(number_str);
    return (len);
}

int add_str_to_str(char *buffer, char *to_add)
{
    my_strcpy(buffer, to_add);
    return (my_strlen(to_add));
}

int my_sprintf_flag(char flag, char *buffer, va_list argptr)
{
    if (flag == 's')
        return (add_str_to_str(buffer, va_arg(argptr, char *))-2);
    if (flag == 'd')
        return (add_int_to_str(buffer, va_arg(argptr, int))-2);
    return (0);
}

char *my_sprintf(char *str, ...)
{
    va_list argptr;
    va_start(argptr, str);
    char buffer[512];
    int index = 0;
    int offset = 0;
    while (str[index]) {
        if (str[index] == '%') {
        index += 1;
        offset += my_sprintf_flag(str[index], buffer+index-1+offset, argptr);
        }
        else
            buffer[index + offset] = str[index];
        index += 1;
    }
    buffer[index+offset] = '\0';
    va_end(argptr);
    return (my_strdup(buffer));
}