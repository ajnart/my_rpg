/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** event_handle.c
*/
#include "main.h"
#include "event_handler.h"

void hdl_key(sfEvent evt, sfRenderWindow *win, struct event_state *state)
{
    // TODO : Handle key events.
}

void hdl_close(sfEvent evt, sfRenderWindow *win)
{
    sfRenderWindow_close(win);
}

void hdl_click(sfEvent evt, sfRenderWindow *win)
{
    // TODO : Handle click events.
}

const struct flagoptions ptr_flags[] = 
{
    {sfEvtMouseButtonPressed, &hdl_click},
    {sfEvtKeyPressed, &hdl_key},
    {sfEvtClosed, &hdl_close},
    {0, 0}
};

void handle_events(sfEvent evt, sfRenderWindow *win)
{
    int i = 0;

    while (ptr_flags[i].evt != 0) {
        if (ptr_flags[i].evt == (int)evt.type)
            ptr_flags[i].function(evt, win);
        i++;
    }
}