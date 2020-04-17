/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <unistd.h>
#include "../../include/lib.h"

int check_flag(char c)
{
    int i = 0;
    char *flags = "dcsb%bSxuopXi";

    while (flags[i]) {
        if (c == flags[i]) {
            return (i);
        }
        i += 1;
    }
    return (-1);
}

static void (*fct_pointers[])(va_list) = {
    funct_int,
    funct_cha,
    funct_str,
    funct_bin,
    funct_per,
    funct_str_maj,
    funct_hexa,
    funct_octa,
    funct_ptr,
    funct_hexa_maj,
    funct_unsign_int,
    funct_int
};

int my_printf(const char *str, ...)
{
    va_list fp;
    va_start(fp, 0);
    size_t i = 0;
    int flag = 0;

    while (str[i]) {
        if (str[i] != '%') {
            write(1, &str[i], 1);
            i += 1;
        } else {
            if ((flag = check_flag(str[i + 1])) != -1)
                fct_pointers[flag](fp);
            else {
                my_putchar('%');
                my_putchar(str[i+1]);
            }
            i += 2;
        }
    }
    return (0);
}