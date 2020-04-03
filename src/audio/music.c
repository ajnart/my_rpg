/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** music.c
*/

#include "main.h"

void play_music(sfRenderWindow *window, char *song, settings_t *settings)
{
    static sfMusic *music;

    if (music == NULL) {
        music = sfMusic_createFromFile(song);
        sfMusic_play(music);
        sfMusic_setVolume(music, settings->volume);
    }
    return;
}
