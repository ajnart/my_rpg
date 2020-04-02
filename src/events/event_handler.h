/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** event_handler.h
*/

#ifndef __EVENT_HANDLER__
#define __EVENT_HANDLER__

struct flagoptions
{
    int evt;
    void (*function)();
};

#endif