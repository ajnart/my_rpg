/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** asset_utils.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/graphlib.h"
#include "../../include/lib.h"

float get_elapsed_time(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return (seconds);
}

char *get_asset_fullpath(char *filename)
{
    char *result = my_strdup("assets/");

    str_append(&result, "/");
    str_append(&result, filename);
    return (result);
}

int get_abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

int get_sign(int nb)
{
    if (nb < 0)
        return (-1);
    return (1);
}