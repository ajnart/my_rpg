/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

void calc_my_putnbr(int nb)
{
    int mod = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 0) {
        mod = nb % 10;
        calc_my_putnbr(nb/10);
        my_putchar(mod + 48);
    }
}

int my_put_nbr(int nb)
{
    if (nb == 0)
        my_putchar('0');
    else
        calc_my_putnbr(nb);
}
