/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg.h
*/

#ifdef __DEBUG__
#undef __DEBUG__
#define __DEBUG__ (1)
#else
#define __DEBUG__ (0)
#endif

#ifndef __RPG__
#define __RPG__


#include "main.h"
#include "emitter.h"
#include "entity.h"

// * Referenced bellow are the functions used for the rpg. gotten via ctags.

// Number : Number of particules
// Max : Max size
// Range : Max range
emitter_t *emitter_setup(int max_div, int number_div,
    int range_div, sfVector3f color);
void play_music(sfRenderWindow *window, char *song);

// * Main loop, calls the other loops:
// Loops: loop_menu // loop_ingame // loop_settings
void perform_loops(sfRenderWindow *window, void (**loop)(),
    void (**loop_old)(), event_st *state, emitter_t *emitter);
void handle_events(sfEvent evt, sfRenderWindow *win,
    event_st *state, void (**loop)());
void print_message(char *str, sfRenderWindow *win, float size,
    sfVector3f info);
sfRectangleShape *mkf_rect(sfFloatRect pos,
    sfTexture *tx, sfColor fill);
void cleanup(sfRenderWindow *w, asset_store_t *a, settings_t *s, emitter_t *e);
void explosion(sfRenderWindow *win, char *str);

float get_elapsed_time(sfClock *clock);
int get_abs(int nb);
int get_sign(int nb);
void update_notifs(sfRenderWindow *win, int request);
void send_notifs(sfRenderWindow *win, char *str, char *substr, int lifeleft);
void add_buttons_paused(int WW, int WH);
#endif