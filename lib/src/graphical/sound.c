/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** music.c
*/

#include "../../include/graphlib.h"
#include "../../include/lib.h"

void play_sound(char *sound, sfRenderWindow *win, int vol)
{
    static sfSound *played;
    if (!played) {
        played = sfSound_create();
    }
    sfSound_setBuffer(played, find_asset_byname(sound)->asset_store.sound);
    sfSound_play(played);
}