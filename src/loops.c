/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loops.c
*/

#include "rpg.h"
#include "lib.h"
#include "emitter.h"
#include "buttons.h"

void perform_loops(sfRenderWindow *win, void (**loop)(),
    void (**loop_old)(), event_st *state, emitter_t *emitter)
{
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
    update_notifs(win, 0);
    sfRenderWindow_display(win);
}