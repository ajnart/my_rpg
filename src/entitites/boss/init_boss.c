/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_boss.c
*/

#include "entity.h"

void init_boss(mob_s *mob)
{
    mob->sprite = sfSprite_create();
    mob->position = (sfVector2f){settings->WW * 3.5, settings->WH * 0.78};
    mob->state = 1;
    mob->rect_i = (sfIntRect){0, 0, 160, 144};
    mob->rect_a = (sfIntRect){0, 0, 160, 144};
    mob->damage = 10;
    mob->speed = 2;
    mob->alive = 1;
    mob->life = 300;
    mob->next = NULL;
    sfSprite_setTexture(mob->sprite,
        find_asset_byname("demon-idle.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->rect_i);
    sfSprite_setScale(mob->sprite,
    (sfVector2f){(double)settings->WW / 700, (double)settings->WH / 500});
    sfSprite_setOrigin(mob->sprite, (sfVector2f){72, 72});
    mob->clock = sfClock_create();
}