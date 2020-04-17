/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** forms.c
*/

#include <stdlib.h>

float create_dir(void)
{
    float percent = (float)(rand() % 101 - 0.1 * 100) / 100. + 0.1;
    float sign = rand() % 2 ? 1 : -1;

    percent = percent * sign;
    return ((float)percent);
}