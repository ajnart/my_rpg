/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** event_handle.c
*/
#include "event_handler.h"
#include "lib.h"
#include "buttons.h"
#include "scenes.h"

const struct flagoptions ptr_flags[] =
{
    {sfEvtMouseButtonPressed, &hdl_click},
    {sfEvtMouseButtonReleased, &hdl_click},
    {sfEvtKeyPressed, &hdl_key},
    {sfEvtKeyReleased, &hdl_released},
    {sfEvtClosed, &hdl_close},
    {-1, NULL},
};

void handle_events(sfEvent evt, sfRenderWindow *win,
    event_st *state, void (**loop)())
{
    int i = 0;

    while (ptr_flags[i].function != NULL) {
        if (ptr_flags[i].evt == (int)evt.type)
            ptr_flags[i].function(evt, win, state, *loop);
        i++;
    }
}