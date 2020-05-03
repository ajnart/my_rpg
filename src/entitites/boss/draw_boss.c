/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** draw_boss.c
*/

#include "entity.h"

void draw_boss_idle(sfRenderWindow *win, mob_s *mob, knight_s *knight)
{
    double x = (double)settings->WW / 700;
    double y = (double)settings->WH / 500;
    sfVector2f scale =
    {mob->position.x - knight->render.position.x > 0 ? x : -x, y};

    if (get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_i.left != 800)
            mob->rect_i.left += 160;
        else
            mob->rect_i.left = 0;
        sfSprite_setTexture(mob->sprite,
            find_asset_byname("demon-idle.png")->asset_store.texture, sfTrue);
        sfSprite_setTextureRect(mob->sprite, mob->rect_i);
        sfSprite_setScale(mob->sprite, scale);
        sfClock_restart(mob->clock);
    }
    mob->rect_a.left = 0;
}

void draw_boss_attacking(sfRenderWindow *win, mob_s *mob, knight_s *knight)
{
    double x = (double)settings->WW / 550;
    double y = (double)settings->WH / 350;
    sfVector2f scale =
    {mob->position.x - knight->render.position.x > 0 ? x : -x, y};

    if (get_elapsed_time(mob->clock) > 0.15) {
        if (mob->rect_a.left != 1600)
            mob->rect_a.left += 160;
        else
            mob->rect_a.left = 0;
        get_damage_boss(knight, mob);
        sfSprite_setTexture(mob->sprite,
            find_asset_byname("demon-attack.png")->asset_store.texture, sfTrue);
        sfSprite_setTextureRect(mob->sprite, mob->rect_a);
        sfSprite_setScale(mob->sprite, scale);
        sfClock_restart(mob->clock);
    }
    mob->rect_i.left = 0;
}