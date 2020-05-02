/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** mob.c
*/

#include "entity.h"

void draw_mob_idle(sfRenderWindow *win, mob_s *mob)
{
    if (get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_i.left <= 2001)
            mob->rect_i.left += 80;
        else
            mob->rect_i.left = 1440;
        sfSprite_setTextureRect(mob->sprite, mob->rect_i);
        sfClock_restart(mob->clock);
    }
    mob->rect_a.left = 0;
    mob->rect_w.left = 2000;
}

void draw_mob_attacking(sfRenderWindow *win, mob_s *mob)
{
    if (get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_a.left <= 721)
            mob->rect_a.left += 80;
        else
            mob->rect_a.left = 0;
        sfSprite_setTextureRect(mob->sprite, mob->rect_a);
        sfClock_restart(mob->clock);
    }
    mob->rect_i.left = 1440;
    mob->rect_w.left = 2000;
}

void draw_mob_walking(sfRenderWindow *win, mob_s *mob)
{
    if (get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_w.left <= 2639)
            mob->rect_w.left += 80;
        else
            mob->rect_w.left = 2000;
        sfSprite_setTextureRect(mob->sprite, mob->rect_w);
        sfClock_restart(mob->clock);
    }
    mob->rect_i.left = 1440;
    mob->rect_a.left = 0;
}

void case_mob(sfRenderWindow *win, mob_s *mob)
{
    switch (mob->state) {
    case 1:
        draw_mob_idle(win, mob);
        break;
    case 2:
        draw_mob_walking(win, mob);
        break;
    case 3:
        draw_mob_attacking(win, mob);
        break;
    default:
        break;
    }
}

void draw_mob(sfRenderWindow *win, mob_s *mob, int k_pos)
{
    if (!mob->sprite)
        mob->sprite = sfSprite_create();
    case_mob(win, mob);
    mob_aggro(mob, k_pos);
    sfSprite_setPosition(mob->sprite, mob->position);
    sfRenderWindow_drawSprite(win, mob->sprite, NULL);
}