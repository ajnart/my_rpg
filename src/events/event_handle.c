/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** event_handle.c
*/
#include "event_handler.h"
#include "lib.h"
#include "buttons.h"

void hdl_key(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    sfRenderWindow_close(win);
}

void hdl_close(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    sfRenderWindow_close(win);
}

void hdl_click(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    sfVector2f mp = { .x = evt.mouseButton.x, .y = evt.mouseButton.y };

    state->type = evt.type;
    state->data = get_button_selected(g_buttons, mp);
}

const struct flagoptions ptr_flags[] = 
{
    {sfEvtMouseButtonPressed, &hdl_click},
    {sfEvtKeyPressed, &hdl_key},
    {sfEvtClosed, &hdl_close},
    {-1, NULL},
};

void handle_events(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    int i = 0;

    // my_printf("Event type : %d\n", evt.type); // ! Button
    while (ptr_flags[i].function != NULL) {
        if (ptr_flags[i].evt == (int)evt.type)
            ptr_flags[i].function(evt, win, state);
        i++;
    }
}