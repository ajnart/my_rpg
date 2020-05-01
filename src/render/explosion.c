/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** explosion.c
*/

#include "rpg.h"
#include "lib.h"

float get_elapsed_time(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return (seconds);
}
