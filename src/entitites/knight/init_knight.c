/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_knight.c
*/
#include "entity.h"

void init_knight(knight_s *knight)
{
    knight->render.sprite = sfSprite_create();
    knight->render.position =
        (sfVector2f){settings->WW * 0.1, settings->WH * 0.92};
    knight->render.state = 1;
    knight->render.rect_i = (sfIntRect){0, 0, 64, 64};
    knight->render.rect_w = (sfIntRect){0, 0, 64, 64};
    knight->render.rect_a = (sfIntRect){0, 0, 64, 64};
    knight->render.is_attacking = 0;
    knight->render.clock = sfClock_create();
    sfSprite_setOrigin(knight->render.sprite, (sfVector2f){32, 32});
    sfSprite_setTexture(knight->render.sprite,
        find_asset_byname("Idle.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(knight->render.sprite, knight->render.rect_i);
    sfSprite_setScale(knight->render.sprite,
    (sfVector2f){(double)settings->WW / 400, (double)settings->WH / 400});
}
// TODO : Load from settings depending on the player's name.
// TODO : Maybe encrypt settings via HASH function.