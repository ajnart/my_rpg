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
    char xorKey = 'P'; 
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) 
        ret[i] = str[i] ^ xorKey; 
    return my_strdup(ret);
}