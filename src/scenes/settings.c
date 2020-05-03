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
        if (my_strcmp(state->data, "backm")) {
            *loop = &loop_menu;
            settings->paused = 0;
        }
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

void messages_settings(sfRenderWindow *win, int WW, int WH)
{
    if (settings->paused == 0)
        print_message(my_sprintf("VOLUME : %d", settings->volume),
            win, 1.2, (sfVector3f){WW*0, WH*0.6, 1});
}

void loop_settings(sfRenderWindow *win, event_st *state, void (**loop)())
{
    settings->paused ? 0: sfRenderWindow_clear(win, sfBlack);
    messages_settings(win, settings->WW, settings->WH);
    if_settings(state, loop);
    sfMusic_setVolume(find_asset_byname("music.wav")->asset_store.music,
        settings->volume);
    state->data = NULL;
}

void buttons_settings(sfRenderWindow *win, int WW, int WH)
{
    sfTexture *tx = find_asset_byname("button.png")->asset_store.texture;

    settings->paused ? add_button(&g_buttons, "backg", mkf_rect((sfFloatRect)
        {WW*0.85, WH*0.9, WW*0.15, WH*0.1}, tx, sfRed), "Back to game"):0;
    settings->paused ? add_button(&g_buttons, "exitg", mkf_rect((sfFloatRect)
        {WW*0.85, WH*0.8, WW*0.15, WH*0.1}, tx, sfGreen), "Save and quit"):0;
    add_button(&g_buttons, "backm", mkf_rect((sfFloatRect)
        {0, WH*0.9, WW*0.15, WH*0.1}, tx, sfRed), "Back to main menu");
    add_button(&g_buttons, "vol_minus", mkf_rect((sfFloatRect)
        {WW*0.075, WH*0.7, WW*0.075, WH*0.1}, tx, sfBlue), "vol -");
    add_button(&g_buttons, "vol_plus", mkf_rect((sfFloatRect)
        {0, WH*0.7, WW*0.075, WH*0.1}, tx, sfRed), "vol +");
    add_button(&g_buttons, "emitter", mkf_rect((sfFloatRect)
        {0, WH*0.8, WW*0.15, WH*0.1}, tx,
        settings->emitter == 0 ? sfRed : sfGreen), "particles on/off");
}