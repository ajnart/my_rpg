/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ingame.c
*/

#include "main.h"
#include "rpg.h"
#include "lib.h"

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
{
    settings->status = "Game";
    print_message(settings->status, win, "font.ttf",
        (sfVector2f){settings->WW * 0.5, settings->WH * 0.1});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
            if (my_strcmp(state->data, "back"))
            *loop = &loop_menu;
    }
}
