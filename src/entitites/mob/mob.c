/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** mob.c
*/

#include "entity.h"

void get_damage(knight_s *knight, mob_s *mob)
{
    if (mob->rect_a.left == 640) {
        knight->stats.health -= mob->damage;
    }
}

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
        draw_mob_attacking(win, mob, &(game->knight));
        break;
    case 4:
        draw_mob_dead(win, mob, game);
    default:
        break;
    }
}

void draw_mob(sfRenderWindow *win, mob_s *mob, int k_pos, game_t *game)
{
    while (mob) {
        case_mob(win, mob, k_pos, game);
        mob_aggro(game->mob, k_pos);
        sfSprite_setPosition(mob->sprite, mob->position);
        sfRenderWindow_drawSprite(win, mob->sprite, NULL);
        if (mob->life <= 0)
            mob->state = 4;
        if (mob->alive == 0) {
            mob = delete_mob(game, mob);
            send_notifs(win, "You have found", "40 Gold!", 20);
        }
        else
            mob = mob->next;
    }
}