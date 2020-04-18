/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu.c
*/

#include "rpg.h"
#include "main.h"
#include "lib.h"

void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)())
{
    play_music(win, "assets/music.ogg", settings);
    print_message(settings->status, win, "font.ttf",
        (sfVector2f){settings->WW * 0.5, settings->WH * 0.1});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        if (my_strcmp(state->data, "bruh"))
            *loop = &loop_ingame;
        if (my_strcmp(state->data, "settings"))
            *loop = &loop_settings;
        if (my_strcmp(state->data, "quit"))
            sfRenderWindow_close(win);
        my_printf("Button clicked: %s❗\n ", state->data);
        state->data = NULL;
    }
}