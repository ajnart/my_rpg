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

char *conver_base(int num, int base)
{
    static char my_base[] = "0123456789ABCDEF";
    static char buffer[50];
    char *ptr = NULL;

    ptr = &buffer[49];
    *ptr = '\0';
    do {
        *--ptr = my_base[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}

int add_int_to_str(char *buffer, int to_add, int pos, char *str)
{
    char *number_str = conver_base(to_add, 10);
    int i = 0;

    for (i = 0; number_str[i]; i++) {
        buffer[pos] = number_str[i];
        pos++;
    }
    return (strlen(number_str));
}

int add_str_to_str(char *buffer, char *to_add, int pos, char *str)
{
    int i = 0;

    while (to_add[i])
    {
        buffer[pos] = to_add[i];
        pos += 1;
        i += 1; 
    }
    return (strlen(to_add));
}

int switch_sprintf(char *str, int i, char *buffer, va_list argptr)
{
    if (str[i + 1] == 'd') {
        return(add_int_to_str(buffer, va_arg(argptr, int), i, str)-1);
    }
    else if (str[i + 1] == 's') {
        return(add_str_to_str(buffer, va_arg(argptr, char *), i, str));
    }
}

char *my_sprintf(char *str, ...)
{
    va_list argptr;
    va_start(argptr, str);
    static char buffer[512];
    int i = 0;
    int pos = 0;

    for (i = 0; str[i]; i++) {
        printf("str[i] : %s", &str[i]);
        if (str[i] != '%') {
            buffer[pos] = str[i];
        }
        else {
            pos += switch_sprintf(str, i, buffer, argptr);
            i += 1;
        }
        pos += 1;
    }
    i += 2;
    buffer[i] = '\0';
    va_end(argptr);
    return (buffer);
}