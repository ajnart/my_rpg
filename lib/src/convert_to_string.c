/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** convert_to_string.c
*/

#include <stdio.h>
#include <stdlib.h>

char *my_revstr(char *str);

char *convert_to_string(int number)
{
    char *str = NULL;
    int num = number;
    int nb_char = 0;
    int i = 0;

    while (num > 0) {
        num /= 10;
        nb_char++;
    } str = malloc(sizeof(char) * nb_char + 5);
    if (!str)
        return NULL;
    for (i = 0; i < nb_char; i++) {
        str[i] = number % 10 + '0';
        number /= 10;
    } for (i; i < 4; i++)
        str[i] = '0';
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
