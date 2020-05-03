/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_mob.c
*/

#include "entity.h"

void set_mob(mob_s *element, sfVector2f pos, sfVector2f(stat), sfColor color)
{
    element->sprite = sfSprite_create();
    element->position = pos;
    element->state = 1;
    element->rect_i = (sfIntRect){1440, 0, 80, 80};
    element->rect_a = (sfIntRect){0, 0, 80, 80};
    element->rect_w = (sfIntRect){2000, 0, 80, 80};
    element->rect_d = (sfIntRect){800, 0, 80, 80};
    element->damage = stat.x;
    element->speed = stat.y;
    element->alive = 1;
    element->life = (stat.x + stat.y) * 20;
    element->next = NULL;
    sfSprite_setTexture(element->sprite,
        find_asset_byname("blob.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(element->sprite, element->rect_i);
    sfSprite_setScale(element->sprite,
    (sfVector2f){(double)settings->WW / 700, (double)settings->WH / 500});
    sfSprite_setColor(element->sprite, color);
    sfSprite_setOrigin(element->sprite, (sfVector2f){40, 40});
    element->clock = sfClock_create();
}

void append_mob(mob_s **mob, sfVector2f pos, sfVector2f dmg_s, sfColor color)
{
    mob_s *tmp = *mob;
    mob_s *element = malloc(sizeof(mob_s));

    set_mob(element, pos, dmg_s, color);
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
    append_mob(mob, (sfVector2f){settings->WW, settings->WH * 0.92},
    (sfVector2f){(float)5, (float)0.1}, sfWhite);
    append_mob(mob, (sfVector2f){settings->WW * 1.2, settings->WH * 0.92},
    (sfVector2f){(float)5, (float)0.1}, sfWhite);
    append_mob(mob, (sfVector2f){settings->WW * 1.3, settings->WH * 0.89},
    (sfVector2f){(float)10, (float)0.3}, sfBlue);
    append_mob(mob, (sfVector2f){settings->WW * 1.5, settings->WH * 0.94},
    (sfVector2f){(float)10, (float)0.3}, sfBlue);
    append_mob(mob, (sfVector2f){settings->WW * 1.7, settings->WH * 0.87},
    (sfVector2f){(float)20, (float)0.1}, sfRed);
    append_mob(mob, (sfVector2f){settings->WW * 1.8, settings->WH * 0.94},
    (sfVector2f){(float)5, (float)0.1}, sfWhite);
    append_mob(mob, (sfVector2f){settings->WW * 2.1, settings->WH * 0.90},
    (sfVector2f){(float)15, (float)0.5}, sfMagenta);
    append_mob(mob, (sfVector2f){settings->WW * 2.5, settings->WH * 0.88},
    (sfVector2f){(float)15, (float)0.5}, sfMagenta);
    append_mob(mob, (sfVector2f){settings->WW * 2.9, settings->WH * 0.94},
    (sfVector2f){(float)15, (float)0.5}, sfMagenta);
}