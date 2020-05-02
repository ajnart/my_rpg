/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** knight_translation.c
*/

#include "knight.h"

void draw_knight_translate(sfRenderWindow *win, knight_s *knight, int way)
{
    if (way == 1) {
        if (knight->render.position.y > settings->WH * 0.86) {
            knight->render.position.y -= 1;
            knight->render.position.x += 1;
            draw_knight_walking(win, knight, 1, 0);
        }
    }
    if (way == 2) {
        if (knight->render.position.y < settings->WH * 0.97) {
            knight->render.position.y += 1;
            knight->render.position.x -= 1;
            draw_knight_walking(win, knight, -1, 0);
        }
    }
}

void move_knight(knight_s *knight, int way)
{
    if (way == 1) {
        if (knight->render.position.x < (double)settings->WW / 6 * 5) {
            knight->render.position.x += settings->WW / 426;
        }
    }
    if (way == -1) {
        if (knight->render.position.x > (double)settings->WW / 6) {
            knight->render.position.x -= 3;
        }
    }
}