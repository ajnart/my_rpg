/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loops.c
*/

#include "rpg.h"
#include "lib.h"
#include "events/buttons.h"
#include "render/render.h"

settings_t *settings;
button_store_t *g_buttons;

void perform_loops(sfRenderWindow *window, void (**loop)(),
    void (**loop_old)(), event_st *state)
{
    sfEvent event;
    set_btn_color(window);
    sfRenderWindow_clear(window, (sfColor){40, 40, 40, 255});
    while (sfRenderWindow_pollEvent(window, &event))
        handle_events(event, window, state);
    if (*loop != *loop_old) {
        scene_btn_loader(*loop, window);
    }
    *loop_old = *loop;
    (*loop)(window, state, loop);
    draw_buttons(window, g_buttons);
    sfRenderWindow_display(window);
}

void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)())
{
    // static int frame = 0;
    // my_printf("Current frame : %d\n", frame); // ! Bebug : Frame counter
    // frame ++;
    play_music(win, "assets/music.ogg", settings);
    print_message("Eat my fucking ass", win, "font.ttf",
        (sfVector2f){settings->WH/2, settings->WW/2});
    if (state->type == sfEvtMouseButtonPressed
        && state->data && my_strcmp(state->data, "quit"))
        sfRenderWindow_close(win);
    my_printf("Button clicked : %s ❗\n ", state->data);
}

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
{
    my_printf("Looping intgame.\n");
}