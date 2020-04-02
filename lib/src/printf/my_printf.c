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
        if (c == flags[i])
            return (1);
        i += 1;
    }
    return (0);
}

void fct_pointers_create(va_list fp, const char *str, int i)
{
    print_compute_t fct_pointers[] = {
        ['d'] = funct_int,
        ['c'] = funct_cha,
        ['s'] = funct_str,
        ['b'] = funct_bin,
        ['%'] = funct_per,
        ['S'] = funct_str_maj,
        ['x'] = funct_hexa,
        ['o'] = funct_octa,
        ['p'] = funct_ptr,
        ['X'] = funct_hexa_maj,
        ['u'] = funct_unsign_int,
        ['i'] = funct_int };
    fct_pointers[str[i+1]](fp);
}

int my_printf(const char *str, ...)
{
    va_list fp;
    va_start(fp, 0);
    size_t i = 0;

    while (str[i]) {
        if (str[i] != '%') {
            write(1, &str[i], 1);
            i += 1;
        } else {
            if (check_flag(str[i + 1]))
                fct_pointers_create(fp, str, i);
            else {
                my_putchar('%');
                my_putchar(str[i+1]);
            }
            i += 2;
        }
    }
    return (0);
}
