/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** boss.c
*/

#include "entity.h"

void move_boss(mob_s *mob, int way)
{
    if (way == 1)
        mob->position.x += 1;
    if (way == -1)
        mob->position.x -= 1;
}

void draw_boss(sfRenderWindow *win, mob_s *mob, game_t *game)
{
    draw_boss_idle(win, mob);
    sfSprite_setPosition(mob->sprite, mob->position);
    sfRenderWindow_drawSprite(win, mob->sprite, NULL);
}