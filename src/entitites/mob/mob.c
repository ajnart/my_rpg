/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** mob.c
*/

#include "entity.h"

void case_mob(sfRenderWindow *win, mob_s *mob, int k_pos, game_t *game)
{
    switch (mob->state) {
    case 1:
        draw_mob_idle(win, mob);
        break;
    case 2:
        draw_mob_walking(win, mob, k_pos);
        break;
    case 3:
        draw_mob_attacking(win, mob);
        break;
    case 4:
        draw_mob_dead(win, mob, game);
    default:
        break;
    }
}

void draw_mob(sfRenderWindow *win, mob_s *mob, int k_pos, game_t *game)
{
    mob_s *save = NULL;

    while (mob) {
        case_mob(win, mob, k_pos, game);
        mob_aggro(mob, k_pos);
        sfSprite_setPosition(mob->sprite, mob->position);
        sfRenderWindow_drawSprite(win, mob->sprite, NULL);
        if (mob->life <= 0)
            mob->state = 4;
        save = mob;
        mob = mob->next;
        if (save->alive == 0)
            free(save);
    }
}