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
    sfIntRect rect;
    sfVector2f position;
    sfSprite *sprite;
};

typedef struct knight_stats {
    int health;
    int gold;
    int maxhealth;
    int strenght;
    int luck;
    int mobility;
};

typedef struct knight_struct {
    struct knight_render render;
    struct knight_stats stats;
} knight_s;