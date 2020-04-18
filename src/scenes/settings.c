/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** settings.c
*/

#include "rpg.h"
#include "main.h"
#include "buttons.h"
#include "lib.h"

void loop_settings(sfRenderWindow *win, event_st *state, void (**loop)())
{
    settings->status = "Settings";
    print_message(settings->status, win, "font.ttf",
        (sfVector2f){settings->WW * 0.2, settings->WH * 0.1});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
            if (my_strcmp(state->data, "back"))
            *loop = &loop_menu;
    }
}

void buttons_settings(sfRenderWindow *win)
{
    const int WW = sfRenderWindow_getSize(win).x;
    const int WH = sfRenderWindow_getSize(win).y;
    add_button(&g_buttons, "back", create_full_rect((sfFloatRect)
            {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Back to main menu");
    print_message("Options", win, "font.ttf", (sfVector2f){WH/2, WW/2});
    add_button(&g_buttons, "vol_minus", create_full_rect((sfFloatRect)
            {WW * 0.6, WH * 0.6, WW*0.2, WH*0.1}, NULL, sfRed), "-");
    add_button(&g_buttons, "vol_plus", create_full_rect((sfFloatRect)
            {WW * 0.4, WH * 0.6, WW*0.2, WH*0.1}, NULL, sfRed), "+");
}