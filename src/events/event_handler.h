/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** event_handler.h
*/

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __EVENT_HANDLER__
#define __EVENT_HANDLER__

struct flagoptions
{
    int evt;
    void (*function)();
};

void hdl_key(sfEvent evt, sfRenderWindow *win, event_st *state);
void hdl_close(sfEvent evt, sfRenderWindow *win, event_st *state);
void hdl_released(sfEvent evt, sfRenderWindow *win, event_st *state);
void hdl_click(sfEvent evt, sfRenderWindow *win, event_st *state);

#endif