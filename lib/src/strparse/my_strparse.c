/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <unistd.h>
#include "../../include/lib.h"

void parse_int(va_list arg)
{
    my_put_nbr(va_arg(arg, int));
}

void parse_str(va_list arg)
{
    char *str = va_arg(arg, char *);
    if (str == NULL) {
        my_putstr("(null)");
        return;
        }
    my_putstr(str);
}

int check_flag_parse(char c)
{
    int i = 0;
    char *flags = "ds";

    while (flags[i]) {
        if (c == flags[i]) {
            return (i);
        }
        i += 1;
    }
    return (-1);
}

static void (*fct_parsers[])(va_list) = {
    parse_int,
    parse_str,
};

void my_putchar_buff(char **str, char c)
{
    int i = 0;

    while (*str[i])
        i ++;
    str[i] = c;
    str[i+1] = '\0';
}

char *my_strparse(const char *str, ...)
{
    va_list fp;
    va_start(fp, 0);
    size_t i = 0;
    int flag = 0;
    char ret[1024];

    while (str[i]) {
        if (str[i] != '%') {
            my_putchar_buff(*ret, str[i]);
            i += 1;
        } else {
            if ((flag = check_flag_parse(str[i + 1])) != -1)
                fct_parsers[flag](fp);
            else {
                my_putchar('%');
                my_putchar(str[i+1]);
            }
            i += 2;
        }
    }
    return (ret);
}
