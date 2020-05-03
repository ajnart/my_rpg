/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** draw_mob.c
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
    mob->rect_d.left = 800;
}

void draw_mob_attacking(sfRenderWindow *win, mob_s *mob, knight_s *knight)
{
    if (get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_a.left != 720)
            mob->rect_a.left += 80;
        else
            mob->rect_a.left = 0;
        get_damage(knight, mob);
        sfSprite_setTextureRect(mob->sprite, mob->rect_a);
        sfClock_restart(mob->clock);
    }
    mob->rect_i.left = 1440;
    mob->rect_w.left = 2000;
    mob->rect_d.left = 800;
}

void draw_mob_walking(sfRenderWindow *win, mob_s *mob, int k_pos)
{
    double x = (double)settings->WW / 700;
    double y = (double)settings->WH / 500;
    sfVector2f scale = {mob->position.x - k_pos > 0 ? x : -x, y};

    if (get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_w.left <= 2639)
            mob->rect_w.left += 80;
        else
            mob->rect_w.left = 2000;
        sfSprite_setTextureRect(mob->sprite, mob->rect_w);
        sfSprite_setScale(mob->sprite, scale);
        sfClock_restart(mob->clock);
    }
    mob->rect_i.left = 1440;
    mob->rect_a.left = 0;
    mob->rect_d.left = 800;
}

void draw_mob_dead(sfRenderWindow *win, mob_s *mob, game_t *game)
{
    if (mob->alive == 1 && get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_d.left <= 1359)
            mob->rect_d.left += 80;
        else
            mob->alive = 0;
        sfSprite_setTextureRect(mob->sprite, mob->rect_d);
        sfClock_restart(mob->clock);
    }
    mob->rect_a.left = 0;
    mob->rect_i.left = 1440;
    mob->rect_w.left = 2000;
}