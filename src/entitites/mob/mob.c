/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** mob.c
*/

#include "entity.h"

void case_mob(sfRenderWindow *win, mob_s *mob, int k_pos)
{
    switch (mob->state) {
    case 1:
        draw_mob_idle(win, mob);
        break;
    case 2:
        draw_mob_walking(win, mob, k_pos);
        break;
    case 3:
        draw_mob_attacking(win, mob);
        break;
    case 4:
        draw_mob_dead(win, mob);
    default:
        break;
    }
}

void draw_mob(sfRenderWindow *win, mob_s *mob, int k_pos)
{
    while (mob) {
        case_mob(win, mob, k_pos);
        mob_aggro(mob, k_pos);
        if (mob->alive == 1) {
            sfSprite_setPosition(mob->sprite, mob->position);
            sfRenderWindow_drawSprite(win, mob->sprite, NULL);
        }
        if (mob->life <= 0)
            mob->state = 4;
        mob = mob->next;
    }
}