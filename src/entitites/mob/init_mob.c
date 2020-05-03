/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_mob.c
*/

#include "entity.h"

void free_mob(mob_s *mob)
{
    mob->alive = 0;
    sfSprite_destroy(mob->sprite);
    sfClock_destroy(mob->clock);
}

void delete_mob(game_t *game, mob_s *mob)
{
    mob_s *tmp = game->mob;
    mob_s *save = NULL;

    if (game->mob->next == NULL) {
        free_mob(game->mob);
        game->mob = NULL;
        return;
    }
    while (tmp->next) {
        if (tmp->next->position.x == mob->position.x &&
        tmp->next->life == mob->life) {
            save = tmp->next;
            tmp->next = tmp->next->next;
            free_mob(save);
        }
        tmp = tmp->next;
    }
}

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
}