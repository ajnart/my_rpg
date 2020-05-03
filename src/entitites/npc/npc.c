/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** npc.c
*/

#include "entity.h"

void move_npc(npc_t *npc, int way)
{
    if (way == 1)
        npc->position.x += 1;
    if (way == -1)
        npc->position.x -= 1;
}

void case_npc(sfRenderWindow *win, npc_t *npc)
{
    switch (npc->state) {
    case 1:
        draw_npc_idle(win, npc);
        break;
    default:
        break;
    }
}

void draw_npc(sfRenderWindow *win, npc_t *npc)
{
    case_npc(win, npc);
    sfSprite_setPosition(npc->sprite, npc->position);
    sfRenderWindow_drawSprite(win, npc->sprite, NULL);
}