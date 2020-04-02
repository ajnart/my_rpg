/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** functs_1.c
*/

#include <stddef.h>
#include "../../include/lib.h"

void funct_int(va_list arg)
{
    my_put_nbr(va_arg(arg, int));
}

void funct_cha(va_list arg)
{
    my_putchar(va_arg(arg, int));
}

void funct_str(va_list arg)
{
    char *str = va_arg(arg, char *);
    if (str == NULL) {
        my_putstr("(null)");
        return;
        }
    my_putstr(str);
}

void funct_octa(va_list arg)
{
    my_putnbr_base(va_arg(arg, unsigned int), "01234567");
}

void funct_str_maj(va_list arg)
{
    char *str = va_arg(arg, char *);
    int i = 0;

    if (str == NULL) {
        my_putstr("(null)");
        return; }
    while (str[i]) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            if (str[i] < 7)
                my_putchar('0');
            if (str[i] < 77)
                my_putchar('0');
            my_putnbr_base(str[i], "01234567");
            i += 1;
        } else {
            my_putchar(str[i]);
            i += 1; }
    }
}
