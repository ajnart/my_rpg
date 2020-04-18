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
    play_music(win, "assets/music.ogg");
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

void buttons_menu(sfRenderWindow *win, int WW, int WH)
{
    sfTexture *texture = find_asset_byname("texture.jpg")->asset_store.texture;
    add_button(&g_buttons, "quit", create_full_rect((sfFloatRect)
            {WW/4, WH * 0.7, WW/2, WH/6}, texture, sfRed), "Ragequit");
        add_button(&g_buttons, "bruh", create_full_rect((sfFloatRect)
            {WW/4, WH * 0.5, WW/2, WH/6}, texture, sfColor_fromRGB(80, 80, 80)), "Bruh button");
        add_button(&g_buttons, "settings", create_full_rect((sfFloatRect)
            {WW/4, WH * 0.3, WW/2, WH/6}, texture, sfWhite), "Settings");
}