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
    if (sfMusic_getStatus(find_asset_byname(song)->asset_store.music) ==
    sfStopped) {
        sfMusic_play(find_asset_byname(song)->asset_store.music);
        sfMusic_setVolume(find_asset_byname(song)->asset_store.music,
            settings->volume);
    }
    return;
}
