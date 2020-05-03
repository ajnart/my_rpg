/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** boss.c
*/

#include "entity.h"

void get_damage_boss(knight_s *knight, mob_s *mob)
{
    int k_pos = knight->render.position.x;

    if (mob->rect_a.left == 1440 && get_abs(k_pos - mob->position.x) < 100) {
        knight->stats.health -= mob->damage;
    }
}

void move_boss(mob_s *mob, int way)
{
    if (way == 1)
        mob->position.x += 1;
    if (way == -1)
        mob->position.x -= 1;
}

void case_boss(sfRenderWindow *win, mob_s *mob, game_t *game)
{
    switch (mob->state) {
    case 1:
        draw_boss_idle(win, mob, &(game->knight));
        break;
    case 2:
        draw_boss_idle(win, mob, &(game->knight));
        break;
    case 3:
        draw_boss_attacking(win, mob, &(game->knight));
        break;
    default:
        break;
    }
}

void draw_boss(sfRenderWindow *win, mob_s *mob, game_t *game)
{
    render_health_bar(win, mob);
    case_boss(win, mob, game);
    mob_aggro(mob, game->knight.render.position.x);
    sfSprite_setPosition(mob->sprite, mob->position);
    if (mob->life <= 0)
        game->npc.state = 3;
    else
        sfRenderWindow_drawSprite(win, mob->sprite, NULL);
}