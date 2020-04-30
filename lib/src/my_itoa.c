/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_itoa.c
*/

#include <stdio.h>
#include <stdlib.h>

void swap(char *o, char *y)
{
    char t = *o;
    *o = *y;
    *y = t;
}

char *swap_char(char *buffer, int start, int end)
{
    while (start < end)
        swap(&buffer[start++], &buffer[end--]);
    return buffer;
}

char *my_itoa(int value, char *buffer, int base)
{
    int num = value < 0 ? value * -1 : value;
    int i = 0;
    int r = 0;
    while (num) {
        r = num % base;
        if (r >= 10)
            buffer[i++] = 65 + (r - 10);
        else
            buffer[i++] = 48 + r;

        num = num / base;
    }
    if (i == 0)
        buffer[i++] = '0';
    if (value < 0 && base == 10)
        buffer[i++] = '-';
    buffer[i] = '\0';
    return swap_char(buffer, 0, i - 1);
}