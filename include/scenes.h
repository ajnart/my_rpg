/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** scenes.h
*/

#ifndef __SCENES__
#define __SCENES__
#include "main.h"

void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)());
void buttons_menu(sfRenderWindow *win, int WW, int WH);

void buttons_settings(sfRenderWindow *win, int WW, int WH);
void loop_settings(sfRenderWindow *win, event_st *state, void (**loop)());

void buttons_ingame(sfRenderWindow *win, int WW, int WH);
void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)());
void loop_howto(sfRenderWindow *win, event_st *state, void (**loop)());

#endif