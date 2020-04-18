/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** music.c
*/

#include <unistd.h>
#include "main.h"
#include "lib.h"

void play_music(sfRenderWindow *window, char *song)
{
    static sfMusic *music;

    if (my_strcmp(song, "cleanup")) {
        sfMusic_destroy(music);
        write(2, "(cleanup) Destroying music...\n", 31);
        return;
    }

    if (music == NULL) {
        music = sfMusic_createFromFile(song);
        sfMusic_play(music);
        sfMusic_setVolume(music, settings->volume);
    }
    return;
}
