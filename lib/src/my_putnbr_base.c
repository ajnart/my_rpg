/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_nbr_base.c
*/

#include "../../include/lib.h"

int shownbr_base(int nbr, int length, char const *base)
{
    int i = 0;

    if (nbr < 0) {
        my_putchar('-');
        i = nbr % length * -1;
        shownbr_base(nbr / length * -1, length, base);
        my_putchar(base[i]);
    }
    if (nbr > 0) {
        i = nbr % length;
        shownbr_base(nbr / length, length, base);
        my_putchar(base[i]);
    }
    return (0);
}

int my_putnbr_base(int nbr, char const *base)
{
    int length = 0;

    while (base[length] != '\0')
        length += 1;
    if (nbr == 0) {
        my_putchar('0');
        return (0);
    }
    return (shownbr_base(nbr, length, base));
}

int shownbr_base_unsigned(unsigned long nbr, int length, char const *base)
{
    int i = 0;

    if (nbr > 0) {
        i = nbr % length;
        shownbr_base_unsigned(nbr / length, length, base);
        my_putchar(base[i]);
    }
    return (0);
}

int my_putnbr_base_unsigned(unsigned long nbr, char const *base)
{
    int length = 0;

    while (base[length] != '\0')
        length += 1;
    if (nbr == 0) {
        my_putchar('0');
        return (0);
    }
    return (shownbr_base_unsigned(nbr, length, base));
}