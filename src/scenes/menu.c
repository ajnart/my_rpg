/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu.c
*/

#include "rpg.h"
#include "main.h"
#include "lib.h"
#include "buttons.h"
#include "scenes.h"

void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)())
{
    play_music(win, "music.ogg");
    print_message("Knight of boulogne !", win, 2,
        (sfVector3f){settings->WW * 0.5, settings->WH * 0.1, 0});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        if (my_strcmp(state->data, "play"))
            send_notifs(win, "Release to play the game !", "", 20);
        if (my_strcmp(state->data, "settings"))
            send_notifs(win, "Release to go to the settings..", "", 20);
        if (my_strcmp(state->data, "quit"))
            send_notifs(win, "gonna cry ?", "", 20);
        state->data = "none";
    }
    if (state->type == sfEvtMouseButtonReleased && state->data) {
        if (my_strcmp(state->data, "play"))
            *loop = &loop_ingame;
        if (my_strcmp(state->data, "settings"))
            *loop = &loop_settings;
        if (my_strcmp(state->data, "quit"))
            sfRenderWindow_close(win);
    }
}

void buttons_menu(sfRenderWindow *win, int WW, int WH)
{
    sfTexture *texture = find_asset_byname("button.png")->asset_store.texture;

    add_button(&g_buttons, "quit", mkf_rect((sfFloatRect)
        {WW/4, WH * 0.7, WW/2, WH/6}, texture, sfRed),
        "Ragequit");
    add_button(&g_buttons, "settings", mkf_rect((sfFloatRect)
        {WW/4, WH * 0.5, WW/2, WH/6}, texture, sfColor_fromRGB(230, 230, 230)),
        "Settings");
    add_button(&g_buttons, "play", mkf_rect((sfFloatRect)
        {WW/4, WH * 0.3, WW/2, WH/6}, texture, sfColor_fromRGB(5, 50, 5)),
        "Play");
    add_button(&g_buttons, "infos", mkf_rect((sfFloatRect)
        {WW/4, WH * 0.9, WW/2, WH/14}, texture, sfColor_fromRGB(255, 102, 255)),
        "How to play?");
}