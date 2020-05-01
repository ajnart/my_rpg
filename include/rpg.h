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
// * Referenced bellow are the functions used for the rpg. gotten via ctags.

settings_t *settings;

// Number : Number of particules
// Max : Max size
// Range : Max range
emitter_t *emitter_setup(int max_div, int number_div, int range_div);
void play_music(sfRenderWindow *window, char *song);

// * Main loop, calls the other loops:
// Loops: loop_menu // loop_ingame // loop_settings
void perform_loops(sfRenderWindow *window, void (**loop)(),
    void (**loop_old)(), event_st *state, emitter_t *emitter);
void handle_events(sfEvent evt, sfRenderWindow *win, event_st *state);
void print_message(char *str, sfRenderWindow *win, char *s_ft,
    sfVector3f info);
sfRectangleShape *create_full_rect(sfFloatRect pos,
    sfTexture *tx, sfColor fill);
void cleanup(sfRenderWindow *w, asset_store_t *a, settings_t *s, emitter_t *e);
void explosion(sfRenderWindow *win, char *str);

// * Precalculated hases :
//  ".png" = 6383219704
//  ".ogg" = 6383218384
//  ".wav" = 6383226913
//  ".jpg" = 6383213236
//  ".ttf" = 6383224257
void asset_type_define(asset_store_t *new, char *ext, char *filename);

#endif