/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loops.c
*/

#include "main.h"
#include "rpg.h"
#include "lib.h"

void perform_mainloop(sfRenderWindow *window, void (**loop)(), void (**loop_old)(), event_st *state)
{
    sfEvent event;
    sfRenderWindow_clear(window, (sfColor){40, 40, 40, 255});
    if (sfRenderWindow_pollEvent(window, &event))
        handle_events(event, window, state);
    *loop_old = *loop;
    (*loop)(window, loop);
    sfRenderWindow_display(window);
}

void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)())
{
    if (state->type == sfEvtMouseButtonPressed
        && state->data && my_strcmp(state->data, "start"))
        *loop = &loop_ingame;
    else if (state->type == sfEvtMouseButtonPressed
        && state->data && my_strcmp(state->data, "quit"))
        sfRenderWindow_close(win);
}

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
{
    if (state->type == sfEvtMouseButtonPressed
        && state->data && my_strcmp(state->data, "back"))
        *loop = &loop_menu;
}
