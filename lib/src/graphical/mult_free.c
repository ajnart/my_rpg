/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** mult_free.c
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void mult_free(int how_much, ...)
{
    va_list ap;
    va_start(ap, how_much);
    char *freeing = NULL;
    int i = 0;

    while (i < how_much) {
        freeing = va_arg(ap, char *);
        free(freeing);
        i++;
    }
}