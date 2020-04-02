/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** functs_2.c
*/

#include "../../include/lib.h"

void funct_per(va_list arg)
{
    int i = (va_arg(arg, int));
    i += 1;
    my_putchar('%');
}

void funct_bin(va_list arg)
{
    my_putnbr_base_unsigned(va_arg(arg, unsigned int), "01");
}

void funct_hexa(va_list arg)
{
    my_putnbr_base_unsigned(va_arg(arg, unsigned int), "0123456789abcdef");
}

void funct_hexa_maj(va_list arg)
{
    my_putnbr_base_unsigned(va_arg(arg, unsigned int), "0123456789ABCDEF");
}

void funct_ptr(va_list arg)
{
    my_putstr("0x");
    my_putnbr_base_unsigned(va_arg(arg, unsigned long), "0123456789abcdef");
}