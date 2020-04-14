/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** render.c
*/

#include "render.h"

sfRectangleShape *create_full_rect(sfFloatRect pos, sfTexture *tx, sfColor fill)
{
    sfRectangleShape *dest = sfRectangleShape_create();

    sfRectangleShape_setPosition(dest,
        (sfVector2f){ .x = pos.left, .y = pos.top });
    sfRectangleShape_setSize(dest,
        (sfVector2f){ .x = pos.width, .y = pos.height });
    if (tx)
        sfRectangleShape_setTexture(dest, tx, sfTrue);
    sfRectangleShape_setFillColor(dest, fill);
    return (dest);
}