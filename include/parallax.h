/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parallax.h
*/

#ifndef __PARALLAX__
#define __PARALLAX__
#include "main.h"

typedef struct parallax {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int speed;
    struct parallax *next;
} t_para;


t_para *set_parallax(void);
void draw_parallax(sfRenderWindow *win, t_para *para, event_st *state, sfVector2f pos);

#endif