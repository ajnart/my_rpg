/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_mob.c
*/

#include "entity.h"

void set_mob(mob_s *element, sfVector2f pos)
{
    element->sprite = sfSprite_create();
    element->position = pos;
    element->state = 1;
    element->rect_i = (sfIntRect){1440, 0, 80, 80};
    element->rect_a = (sfIntRect){0, 0, 80, 80};
    element->rect_w = (sfIntRect){2000, 0, 80, 80};
    element->rect_d = (sfIntRect){800, 0, 80, 80};
    element->damage = 1;
    element->alive = 1;
    element->life = 100;
    element->next = NULL;
    sfSprite_setTexture(element->sprite,
        find_asset_byname("blob.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(element->sprite, element->rect_i);
    sfSprite_setScale(element->sprite,
    (sfVector2f){(double)settings->WW / 700, (double)settings->WH / 500});
    sfSprite_setOrigin(element->sprite, (sfVector2f){40, 40});
    element->clock = sfClock_create();
}

void append_mob(mob_s **mob, sfVector2f pos)
{
    mob_s *tmp = *mob;
    mob_s *element = malloc(sizeof(mob_s));

    set_mob(element, pos);
    if (tmp == NULL)
        *mob = element;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = element;
    }
}

void init_mob(mob_s **mob)
{
    *mob = NULL;
    append_mob(mob, (sfVector2f){settings->WW / 3, settings->WH * 0.92});
    append_mob(mob, (sfVector2f){settings->WW / 2, settings->WH * 0.92});
}