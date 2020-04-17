/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_sprintf.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char *convert(int num, int base)
{
    static char my_base[] = "0123456789ABCDEF";
    static char buffer[50];
    char *ptr = NULL;

    ptr = &buffer[49];
    *ptr = '\0';
    do
    {
        *--ptr = my_base[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}

static void buf_to_i(int i, char *buf, char *str)
{
    if (i < 0)
    {
        i = -i;
        *buf = '-';
        buf++;
    }
    str = convert(i, 10);
    while (*str != '\0')
    {
        *buf = *str;
        str++;
        buf++;
    }
}

static int skip(char *compare_to, char *buf)
{
        while (*compare_to != '%') {
        *buf = *compare_to;
        if (*compare_to == '\0')
            return (1);
        buf++;
        compare_to++;
        }
        if (*compare_to == '\0')
            return (1);
    return (0);
}

static void goto_end(char *str, char *buf)
{
    while (*str != '\0') {
        *buf = *str;
        str++;
        buf++;
    }
}

void my_sprintf(char *buf, char const *ap, ...)
{
    char *compare_to; int i = 0; char *str; va_list arg; va_start(arg, ap);

    for (compare_to = (char *)ap; *compare_to != '\0'; compare_to++) {
        if (!skip(&*compare_to, &*buf))
            break;
        compare_to++;
        switch (*compare_to) {
        case 'd':
            i = va_arg(arg, int);
            buf_to_i(i, &*buf, &*str);
            break;
        case 's':
            str = va_arg(arg, char *);
            goto_end(&*str, &*buf);
            break;
        default:
            break;
        }
    }
    *buf = '\0';
    va_end(arg);
}