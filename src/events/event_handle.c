/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** event_handle.c
*/
#include "main.h"
#include "event_handler.h"

void hdl_key(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    // TODO : Handle key events.
}

void hdl_close(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    sfRenderWindow_close(win);
}

void hdl_click(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    sfRenderWindow_close(win);
}

const struct flagoptions ptr_flags[] = 
{
    {sfEvtMouseButtonPressed, &hdl_click},
    {sfEvtKeyPressed, &hdl_key},
    {sfEvtClosed, &hdl_close},
    {0, 0}
};

void handle_events(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    int i = 0;

    while (ptr_flags[i].evt != 0) {
        if (ptr_flags[i].evt == (int)evt.type)
            ptr_flags[i].function(evt, win, state);
        i++;
    }
}