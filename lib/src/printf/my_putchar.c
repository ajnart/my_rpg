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

void disp_nbr(int nb)
{
    char n;

    if (nb < 0) {
        my_putchar('-');
        n = nb % 10 * -1 + '0';
        disp_nbr(nb / -10);
        my_putchar(n);
    }
    if (nb > 0) {
        n = nb % 10 + '0';
        disp_nbr(nb / 10);
        my_putchar(n);
    }
}

int my_put_nbr(int nb)
{

    if (nb == 0) {
        my_putchar('0');
        return (1);
    }
    disp_nbr(nb);
    return (0);
}