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
#include "entity.h"

void perform_loops(sfRenderWindow *win, void (**loop)(),
    void (**loop_old)(), event_st *state, emitter_t *emitter)
{
    static sfEvent event;
    static game_t *game;

    if (!settings->game_defined)
        game = init_game();
    set_btn_color(win);
    while (sfRenderWindow_pollEvent(win, &event))
        handle_events(event, win, state, loop);
    if (*loop != *loop_old) {
        scene_btn_loader(*loop, win);
    }
    *loop_old = *loop;
    (*loop)(win, state, loop, game);
    draw_buttons(win, g_buttons);
    if (settings->emitter == 1 && !settings->paused)
        display_particles(win, emitter, sfMouse_getPositionRenderWindow(win));
    update_notifs(win, 0);
    sfRenderWindow_display(win);
}