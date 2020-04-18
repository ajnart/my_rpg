/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** buttons.h
*/

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __BUTTON_H
#define __BUTTON_H

typedef struct button {
    char *btn_id;
    sfRectangleShape *render;
    sfColor normal;
    struct button *next;
    sfText *text;
} button_store_t;

button_store_t *g_buttons;

void add_button(button_store_t **store, char *id,
    sfRectangleShape *render, char *text);

void destroy_buttons(button_store_t **store);

void draw_buttons(sfRenderWindow *win, button_store_t *store);

button_store_t *get_button(const button_store_t *store, char *name);

void set_btn_color(sfRenderWindow *win);

char *get_button_selected(const button_store_t *store, sfVector2f pos);

void scene_btn_loader(void (*loop)(), sfRenderWindow *win);

#endif //__BUTTON_H