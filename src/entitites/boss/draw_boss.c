/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** draw_boss.c
*/

#include "entity.h"

void draw_boss_idle(sfRenderWindow *win, mob_s *mob, knight_s *knight)
{
    if (get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_i.left != 800)
            mob->rect_i.left += 160;
        else
            mob->rect_i.left = 0;
        get_damage_boss(knight, mob);
        sfSprite_setTextureRect(mob->sprite, mob->rect_i);
        sfClock_restart(mob->clock);
    }
}