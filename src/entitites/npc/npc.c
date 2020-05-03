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

void check_interact(sfRenderWindow *win, npc_t *npc)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f n_pos = npc->position;

    if (m_pos.x >= n_pos.x - 40 && m_pos.x <= n_pos.x + 40 &&
    m_pos.y >= n_pos.y - 40 && m_pos.y <= n_pos.y + 40) {
        if (npc->state == 0)
            npc->state = 1;
        if (npc->state == 1)
            npc->state = 2;
    }
}

void draw_npc(sfRenderWindow *win, npc_t *npc)
{
    draw_npc_idle(win, npc);
    check_interact(win, npc);
    sfSprite_setPosition(npc->sprite, npc->position);
    sfRenderWindow_drawSprite(win, npc->sprite, NULL);
}