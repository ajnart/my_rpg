/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** knight.c
*/

#include "knight.h"

void draw_knight_idle(sfRenderWindow *win, knight_s *knight)
{
    if (get_elapsed_time(knight->render.clock) > 0.1) {
        if (knight->render.rect_i.left <= 887)
            knight->render.rect_i.left += 64;
        else
            knight->render.rect_i.left = 0;
        sfSprite_setTexture(knight->render.sprite,
            find_asset_byname("Idle.png")->asset_store.texture, sfTrue);
        sfSprite_setTextureRect(knight->render.sprite, knight->render.rect_i);
        sfClock_restart(knight->render.clock);
    }
    knight->render.rect_a.left = 0;
    knight->render.rect_w.left = 0;
}

void draw_knight_walking(sfRenderWindow *win, knight_s *knight,
int way, int move)
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
    if (move == 1)
        move_knight(knight, way);
}

void draw_knight_attacking(sfRenderWindow *win, knight_s *knight)
{
    sfVector2f scale = {sfSprite_getScale(knight->render.sprite).x,
    (double)settings->WH / 400};

    if (get_elapsed_time(knight->render.clock) > 0.1) {
        if (knight->render.rect_a.left != 448)
            knight->render.rect_a.left += 64;
        else
            knight->render.is_attacking = 0;
        sfSprite_setTexture(knight->render.sprite,
            find_asset_byname("Attack.png")->asset_store.texture, sfTrue);
        sfSprite_setTextureRect(knight->render.sprite, knight->render.rect_a);
        sfSprite_setScale(knight->render.sprite, scale);
        sfClock_restart(knight->render.clock);
    }
    knight->render.rect_i.left = 0;
    knight->render.rect_w.left = 0;
}

void case_knight(sfRenderWindow *win, knight_s *knight)
{
    switch (knight->render.state) {
    case 1:
        draw_knight_idle(win, knight);
        break;
    case 2:
        draw_knight_walking(win, knight, 1, 1);
        break;
    case 3:
        draw_knight_attacking(win, knight);
        break;
    case 4:
        draw_knight_walking(win, knight, -1, 1);
        break;
    case 5:
        draw_knight_translate(win, knight, 1);
        break;
    case 6:
        draw_knight_translate(win, knight, 2);
        break;
    default:
        break; }
}

void draw_knight(sfRenderWindow *win, knight_s *knight)
{
    if (!knight->render.sprite)
        knight->render.sprite = sfSprite_create();
    case_knight(win, knight);
    sfSprite_setPosition(knight->render.sprite, knight->render.position);
    sfRenderWindow_drawSprite(win, knight->render.sprite, NULL);
}