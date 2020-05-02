/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** settings.h
*/

#ifndef __SETTINGS__
#define __SETTINGS__

typedef struct keys_struct
{
    char *up;
    char *down;
    char *left;
    char *right;
    char *pause;
    char *inv;
} sfKeys_t;

typedef struct settings_struct
{
    int WH;
    int WW;
    int volume;
    int emitter;
    char *name;
    char *status;
    sfKeys_t *keys;
    int game_defined;
} settings_t;

settings_t *load_settings(void);

#endif