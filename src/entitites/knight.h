/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** knight.h
*/

#pragma once

#include "rpg.h"

typedef struct knight_render {
    int state;
    int state_frame;
    int is_attacking;
    sfIntRect rect_i;
    sfIntRect rect_w;
    sfIntRect rect_a;
    sfVector2f position;
    sfSprite *sprite;
    sfClock *clock;
} knight_render;

typedef struct knight_stats {
    int health;
    int gold;
    int maxhealth;
    int strenght;
    int luck;
    int mobility;
} knight_stats;

typedef struct knight_struct {
    struct knight_render render;
    struct knight_stats stats;
} knight_s;

void draw_knight(sfRenderWindow *win, knight_s *knight);
void draw_knight_translate(sfRenderWindow *win, knight_s *knight, int way);
void move_knight(knight_s *knight, int way);
void draw_knight_walking(sfRenderWindow *win, knight_s *knight, int way);