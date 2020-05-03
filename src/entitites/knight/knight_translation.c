/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** knight_translation.c
*/

#include "entity.h"

int check_collision_translate(game_t *game, int way, int k_x, int k_y)
{
    mob_s *mob = game->mob;
    int x = settings->WW / 58;

    if (way == 1) {
        while (mob) {
            if (k_y - x <= mob->position.y &&
            k_y >= mob->position.y && k_x >= mob->position.x - x &&
            k_x <= mob->position.x + x)
                return (0);
            mob = mob->next;
        }
    } else {
        while (mob) {
            if (k_y + x >= mob->position.y &&
            k_y <= mob->position.y && k_x <= mob->position.x + x &&
            k_x >= mob->position.x - x)
                return (0);
            mob = mob->next;
        }
    }
    return (1);
}

int check_collision_move(game_t *game, int way)
{
    mob_s *mob = game->mob;
    int k_x = game->knight.render.position.x;
    int k_y = game->knight.render.position.y;
    int x = settings->WW / 25;
    int y = settings->WW / 64;

    if (way == 1) {
        while (mob) {
            if (k_x + x >= mob->position.x && k_x <= mob->position.x
            && k_y <= mob->position.y + y && k_y >= mob->position.y - y)
                return (0);
            mob = mob->next;
        }
    } else {
        while (mob) {
            if (k_x - x <= mob->position.x && k_x >= mob->position.x
            && k_y >= mob->position.y - y && k_y <= mob->position.y + y)
                return (0);
            mob = mob->next;
        }
    } return (1);
}

void draw_knight_translate(sfRenderWindow *win, game_t *game,
knight_s *knight, int way)
{
    int k_x = game->knight.render.position.x;
    int k_y = game->knight.render.position.y;

    if (way == 1 && check_collision_translate(game, way, k_x, k_y)) {
        if (knight->render.position.y > settings->WH * 0.86) {
            knight->render.position.y -= 1;
            knight->render.position.x += 1;
            draw_knight_walking(win, knight, 1);
        }
    }
    if (way == 2 && check_collision_translate(game, way, k_x, k_y)) {
        if (knight->render.position.y < settings->WH * 0.97) {
            knight->render.position.y += 1;
            knight->render.position.x -= 1;
            draw_knight_walking(win, knight, -1);
        }
    }
}

void move_knight(game_t *game, int way)
{
    if (way == 1 && check_collision_move(game, way)) {
        if (game->knight.render.position.x < (double)settings->WW / 6 * 5)
            game->knight.render.position.x += game->knight.stats.mobility;
    }
    if (way == -1 && check_collision_move(game, way)) {
        if (game->knight.render.position.x > (double)settings->WW / 6)
            game->knight.render.position.x -= game->knight.stats.mobility;
    }
}