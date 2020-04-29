/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}