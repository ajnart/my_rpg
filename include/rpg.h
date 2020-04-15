/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg.h
*/

#ifndef __RPG__
#define __RPG__

#include "main.h"
#include "emitter.h"
// * Referenced bellow are the functions used for the rpg. gotten via ctags. * \\


// Number : Number of particules
// Max : Max size
// Range : Max range
emitter_t *emitter_setup(int max_div, int number_div, int range_div);
void play_music(sfRenderWindow *window, char *song, settings_t *settings);
void perform_loops(sfRenderWindow *window, void (**loop)(), void (**loop_old)(), event_st *state, emitter_t *emitter);
void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)());
void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)());
void handle_events(sfEvent evt, sfRenderWindow *win, event_st *state);
void print_message(char *str, sfRenderWindow *win, char *s_ft,
    sfVector2f info, sfColor color);
#endif