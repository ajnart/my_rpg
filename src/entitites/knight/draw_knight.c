/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** draw_knight.c
*/

#include "entity.h"

void draw_knight_idle(sfRenderWindow *win, knight_s *knight)
{
    if (get_elapsed_time(knight->render.clock) > 0.1) {
        if (knight->render.rect_i.left <= 887)
            knight->render.rect_i.left += 64;
        else
            knight->render.rect_i.left = 0;
        if (rand() % 50 > 30 && knight->stats.health < knight->stats.maxhealth)
            knight->stats.health += knight->stats.maxhealth / 100;
        sfSprite_setTexture(knight->render.sprite,
            find_asset_byname("Idle.png")->asset_store.texture, sfTrue);
        sfSprite_setTextureRect(knight->render.sprite, knight->render.rect_i);
        sfClock_restart(knight->render.clock);
    }
    knight->render.rect_a.left = 0;
    knight->render.rect_w.left = 0;
}

void draw_knight_walking(sfRenderWindow *win, knight_s *knight, int way)
{
    sfVector2f scale = {(double)settings->WW / 400 * way,
    (double)settings->WH / 400};

    if (get_elapsed_time(knight->render.clock) > 0.1) {
        if (knight->render.rect_w.left <= 447)
            knight->render.rect_w.left += 64;
        else
            knight->render.rect_w.left = 0;
        sfSprite_setTexture(knight->render.sprite,
            find_asset_byname("Run.png")->asset_store.texture, sfTrue);
        sfSprite_setTextureRect(knight->render.sprite, knight->render.rect_w);
        sfSprite_setScale(knight->render.sprite, scale);
        sfClock_restart(knight->render.clock);
    }
    knight->render.rect_a.left = 0;
    knight->render.rect_i.left = 0;
}

void draw_knight_attacking(sfRenderWindow *win, knight_s *knight,
mob_s *mob, mob_s *boss)
{
    sfVector2f scale = {sfSprite_getScale(knight->render.sprite).x,
    (double)settings->WH / 400};
    knight->render.rect_a.left == 64 ? play_sound("swing.ogg", win, 10) : 0;
    if (get_elapsed_time(knight->render.clock) > 0.1) {
        if (knight->render.rect_a.left != 448)
            knight->render.rect_a.left += 64;
        else
            knight->render.is_attacking = 0;
        do_damage(mob, knight, get_sign(scale.x));
        do_damage(boss, knight, get_sign(scale.x));
        sfSprite_setTexture(knight->render.sprite,
            find_asset_byname("Attack.png")->asset_store.texture, sfTrue);
        sfSprite_setTextureRect(knight->render.sprite, knight->render.rect_a);
        sfSprite_setScale(knight->render.sprite, scale);
        sfClock_restart(knight->render.clock);
    }
    knight->render.rect_i.left = 0;
    knight->render.rect_w.left = 0;
}