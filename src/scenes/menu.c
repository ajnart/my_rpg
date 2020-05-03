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

void add_rect_text(sfRenderWindow *win, rect_text *info);

void if_menu(sfRenderWindow *win, event_st *state, void (**loop)())
{
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        if (my_strcmp(state->data, "play"))
            send_notifs(win, "Release to play the game !", "", 40);
        if (my_strcmp(state->data, "settings"))
            send_notifs(win, "Release to go to the settings..", "", 40);
        if (my_strcmp(state->data, "quit"))
            send_notifs(win, "gonna cry ?", "", 40);
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

void loop_menu(sfRenderWindow *win, event_st *state,
    void (**loop)(), game_t *game)
{
    int WW = settings->WW;
    int WH = settings->WH;
    sfText *text = sfText_create();
    rect_text info;
    sfRectangleShape *render;
    render = mkf_rect((sfFloatRect){WW*0.15, WH*0.10, WW*0.65, WH* 0.15},
            find_asset_byname("button.png")->asset_store.texture, sfBlue);
    info = (rect_text){render, text, "Knight of boulogne !", sfWhite, 9};
    sfRenderWindow_clear(win, (sfColor){0, 0, 0, 255});
    play_music(win, "music.wav");
    if_menu(win, state, loop);
    add_rect_text(win, &info);
    sfText_destroy(text);
    sfRectangleShape_destroy(render);
}

void buttons_menu(sfRenderWindow *win, int WW, int WH)
{
    sfTexture *texture = find_asset_byname("button.png")->asset_store.texture;

    add_button(&g_buttons, "quit", mkf_rect((sfFloatRect)
        {WW/4, WH * 0.7, WW/2, WH/6}, texture, sfRed),
        "Ragequit");
    add_button(&g_buttons, "settings", mkf_rect((sfFloatRect)
        {WW/4, WH * 0.5, WW/2, WH/6}, texture, sfColor_fromRGB(230, 230, 230)),
        "Settings / How to play");
    add_button(&g_buttons, "play", mkf_rect((sfFloatRect)
        {WW/4, WH * 0.3, WW/2, WH/6}, texture, sfColor_fromRGB(5, 50, 5)),
        "Play");
}