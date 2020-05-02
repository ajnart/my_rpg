/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** knight_translation.c
*/

#include "entity.h"

int check_collision(game_t *game, int way)
{
    mob_s *mob = game->mob;
    int x = settings->WW / 25;
    int y = settings->WW / 64;

    if (way == 1) {
        while (mob) {
            if (game->knight.render.position.x + x >= mob->position.x &&
            game->knight.render.position.y <= mob->position.y + y &&
            game->knight.render.position.y >= mob->position.y - y)
                return (0);
            mob = mob->next;
        }
    }
    return (1);
}

void draw_knight_translate(sfRenderWindow *win, knight_s *knight, int way)
{
    if (way == 1) {
        if (knight->render.position.y > settings->WH * 0.86) {
            knight->render.position.y -= 1;
            knight->render.position.x += 1;
            draw_knight_walking(win, knight, 1);
        }
    }
    if (way == 2) {
        if (knight->render.position.y < settings->WH * 0.97) {
            knight->render.position.y += 1;
            knight->render.position.x -= 1;
            draw_knight_walking(win, knight, -1);
        }
    }
}

void move_knight(game_t *game, int way)
{
    if (way == 1 && check_collision(game, way)) {
        if (game->knight.render.position.x < (double)settings->WW / 6 * 5)
            game->knight.render.position.x += settings->WW / 426;
    }
    if (way == -1 && check_collision(game, way)) {
        if (game->knight.render.position.x > (double)settings->WW / 6)
            game->knight.render.position.x -= settings->WW / 426;
    }
}