/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** settings.h
*/

#ifndef __SETTINGS__
#define __SETTINGS__

typedef struct settings
{
    int WH;
    int WW;
    int volume;
} settings_t;

settings_t *load_settings(void);

#endif