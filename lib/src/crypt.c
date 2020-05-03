/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** crypt.c
*/

#include "../../include/lib.h"

char *encrypt(char *str)
{
    char ret[500];
    char xor = 13;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++)
        ret[i] = str[i] ^ xor;
    return my_strdup(ret);
}