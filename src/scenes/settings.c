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
#include "scenes.h"

void if_settings(event_st *state, void (**loop)())
{
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        if (my_strcmp(state->data, "backm"))
            *loop = &loop_menu;
        if (my_strcmp(state->data, "backg")) {
            settings->paused = 0;
            *loop = &loop_ingame;
        }
        if (my_strcmp(state->data, "vol_plus") && settings->volume <= 90)
            settings->volume += 10;
        if (my_strcmp(state->data, "vol_minus") && settings->volume >= 10)
            settings->volume -= 10;
        if (my_strcmp(state->data, "emitter")) {
            settings->emitter = settings->emitter == 0 ? 1 : 0;
            get_button(g_buttons, "emitter")->normal = get_button(g_buttons,
                "emitter")->normal.g == 255 ? sfRed : sfGreen;
        }
    }
}

void messages_settings(sfRenderWindow *win)
{
    int WW = settings->WW;
    int WH = settings->WH;

    print_message(my_sprintf("Resolution : %d x %d", WW, WH),
        win, 1, (sfVector3f){WW * 0.2, WH * 0.4, 0});
    print_message(my_sprintf("Volume : %d", settings->volume),
        win, 1, (sfVector3f){WW * 0.2, WH * 0.2, 0});
    print_message("Emitter:",
        win, 1, (sfVector3f){WW * 0.2, WH * 0.25, 0});
}

void loop_settings(sfRenderWindow *win, event_st *state, void (**loop)())
{
    messages_settings(win);
    if_settings(state, loop);
    sfMusic_setVolume(find_asset_byname("music.ogg")->asset_store.music,
        settings->volume);
    state->data = NULL;
}

void buttons_settings(sfRenderWindow *win, int WW, int WH)
{
    settings->paused ? add_button(&g_buttons, "backg", mkf_rect((sfFloatRect)
        {WW*0.9, WH*0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Back to game") : 0;
    add_button(&g_buttons, "backm", mkf_rect((sfFloatRect)
        {0, WH*0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Back to main menu");
    add_button(&g_buttons, "vol_minus", mkf_rect((sfFloatRect)
        {WW * 0.35, WH * 0.17, WW*0.05, WH*0.05}, NULL, sfBlue), "");
    add_button(&g_buttons, "vol_plus", mkf_rect((sfFloatRect)
        {WW * 0.40, WH * 0.17, WW*0.05, WH*0.05}, NULL, sfRed), "");
    add_button(&g_buttons, "emitter", mkf_rect((sfFloatRect)
        {WW * 0.35, WH * 0.225, WW*0.1, WH*0.05}, NULL,
        settings->emitter == 0 ? sfRed : sfGreen), "");
}