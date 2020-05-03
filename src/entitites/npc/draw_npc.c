/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_npc.c
*/

#include "entity.h"

void draw_npc_idle(sfRenderWindow *win, npc_t *npc)
{
    if (get_elapsed_time(npc->clock) > 0.2) {
        if (npc->rect_i.left != 720)
            npc->rect_i.left += 80;
        else
            npc->rect_i.left = 0;
        sfSprite_setTextureRect(npc->sprite, npc->rect_i);
        sfClock_restart(npc->clock);
    }
}