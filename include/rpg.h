/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg.h
*/

#ifndef __RPG__
#define __RPG__

#include "main.h"
// * Referenced bellow are the functions used for the rpg. gotten via ctags. * \\

void perform_mainloop(sfRenderWindow *window, void (**loop)(), void (**loop_old)(), event_st *state);
void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)());
void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)());
void handle_events(sfEvent evt, sfRenderWindow *win, event_st *state);
#endif