/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loops.c
*/

#include "rpg.h"
#include "lib.h"
#include "emitter.h"
#include "events/buttons.h"
#include "render/render.h"

settings_t *settings;
button_store_t *g_buttons;

void perform_loops(sfRenderWindow *win, void (**loop)(),
    void (**loop_old)(), event_st *state, emitter_t *emitter)
{
    sfRenderWindow_clear(win, (sfColor){40, 40, 40, 255});
    static sfEvent event;
    set_btn_color(win);
    while (sfRenderWindow_pollEvent(win, &event))
        handle_events(event, win, state);
    if (*loop != *loop_old) {
        scene_btn_loader(*loop, win);
    }
    *loop_old = *loop;
    (*loop)(win, state, loop);
    draw_buttons(win, g_buttons);
    if (settings->emitter == 1)
        display_particles(win, emitter, sfMouse_getPositionRenderWindow(win));
    sfRenderWindow_display(win);
}

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

void loop_settings(sfRenderWindow *win, event_st *state, void (**loop)())
{
    settings->status = "Settings";
    print_message(settings->status, win, "font.ttf",
        (sfVector2f){settings->WW * 0.5, settings->WH * 0.1});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
            if (my_strcmp(state->data, "back"))
            *loop = &loop_menu;
    }
}

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