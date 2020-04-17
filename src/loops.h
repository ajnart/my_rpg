/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loops.h
*/

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __LOOPS_H__
#define __LOOPS_H__

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)());
void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)());
void loop_settings(sfRenderWindow *win, event_st *state, void (**loop)());

#endif