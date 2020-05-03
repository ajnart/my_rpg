/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_npc->c
*/

#include "entity.h"

void init_npc(npc_t *npc)
{
    npc->sprite = sfSprite_create();
    npc->position = (sfVector2f){settings->WW * 0.5, settings->WH * 0.8};
    npc->state = 0;
    npc->text = -1;
    npc->rect_i = (sfIntRect){0, 0, 80, 80};
    npc->clock = sfClock_create();
    npc->clicked = sfClock_create();
    sfSprite_setOrigin(npc->sprite, (sfVector2f){40, 40});
    sfSprite_setTexture(npc->sprite,
        find_asset_byname("wizard_idle.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(npc->sprite, npc->rect_i);
    sfSprite_setScale(npc->sprite,
    (sfVector2f){(double)settings->WW / 400, (double)settings->WH / 400});
}