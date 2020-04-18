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

void loop_settings(sfRenderWindow *win, event_st *state, void (**loop)())
{
    char *buffer = malloc(sizeof(char) * 50);
    settings->status = "Settings";
    print_message(settings->status, win, "font.ttf",
        (sfVector2f){settings->WW * 0.2, settings->WH * 0.1});
    sprintf(buffer, "Volume : %d", settings->volume);
    print_message(buffer, win, "font.ttf", (sfVector2f){settings->WH/2, settings->WW/2});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        if (my_strcmp(state->data, "back"))
            *loop = &loop_menu;
        if (my_strcmp(state->data, "vol_plus"))
            settings->volume += 10;
        if (my_strcmp(state->data, "vol_minus"))
            settings->volume -= 10;
        my_printf("Button clicked: %s❗\n ", state->data);
    }
    sfMusic_setVolume(find_asset_byname("music.ogg")->asset_store.music, settings->volume);

    state->data = NULL;
    free(buffer);
}

void buttons_settings(sfRenderWindow *win, int WW, int WH)
{
    add_button(&g_buttons, "back", create_full_rect((sfFloatRect)
            {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Back to main menu");
    add_button(&g_buttons, "vol_minus", create_full_rect((sfFloatRect)
            {WW * 0.6, WH * 0.6, WW*0.2, WH*0.1}, NULL, sfRed), "-");
    add_button(&g_buttons, "vol_plus", create_full_rect((sfFloatRect)
            {WW * 0.4, WH * 0.6, WW*0.2, WH*0.1}, NULL, sfRed), "+");
}