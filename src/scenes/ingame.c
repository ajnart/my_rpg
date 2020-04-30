/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ingame.c
*/

#include "main.h"
#include "rpg.h"
#include "lib.h"
#include "buttons.h"
#include "scenes.h"

void buttons_ingame(sfRenderWindow *win, int WW, int WH)
{
    add_button(&g_buttons, "back", create_full_rect((sfFloatRect)
            {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Back to main menu");
}

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
{
    settings->status = "Game";
    print_message(settings->status, win, "font.ttf",
        (sfVector3f){settings->WW * 0.5, settings->WH * 0.1, 0});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
            if (my_strcmp(state->data, "back"))
                send_notifs(win, "Gold won!", "You have won 100 GOLD");
                *loop = &loop_menu;
            if (my_strcmp(state->data, "paused")) {
                explosion(win, state->data);
                *loop = &loop_settings;
            }
    }
}