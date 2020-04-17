/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** functs_3.c
*/

#include <stdlib.h>
#include "../../include/lib.h"

void funct_unsign_int(va_list arg)
{
    my_put_nbr_unsigned(va_arg(arg, unsigned int));
}

void disp_nbr_unsigned(unsigned int nb)
{
    char n;

    if (nb > 0) {
        n = nb % 10 + '0';
        disp_nbr_unsigned(nb / 10);
        my_putchar(n);
    }
}

int my_put_nbr_unsigned(unsigned int nb)
{
    char n;

    if (nb == 0) {
        my_putchar('0');
        return (1);
    } else {
        n = nb % 10 + '0';
        disp_nbr_unsigned(nb / 10);
        my_putchar(n);
    }
    return (0);
}

char *my_strcat(char *str1, char *str2)
{
    char *str = NULL;
    int i = 0;
    int num = 0;

    for (i = 0; str1[i]; i += 1)
        num += 1;
    for (i = 0; str2[i]; i += 1)
        num += 1;
    str = malloc(sizeof(char) * num + 1);
    i = 0;
    while (*str1 != '\0')
        str[i++] = *str1++;
    while (*str2 != '\0')
        str[i++] = *str2++;
    str[num] = '\0';
    return (str);
}