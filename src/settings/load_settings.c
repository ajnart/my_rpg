/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** load_settings.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "buttons.h"
#include "lib.h"
#include "rpg.h"

sfKeys_t *load_keys(void)
{
    sfKeys_t *ret = malloc(sizeof(sfKeys_t));
    char **settings = NULL;
    int fd = open("settings.csv", O_RDONLY);
    int i = 0;

    for (i = 0; i < 4; i++)
        get_next_line(fd);
    settings = my_str_to_wordtab(get_next_line(fd), ',');
    ret->up    = settings[0];
    ret->left  = settings[1];
    ret->down  = settings[2];
    ret->right = settings[3];
    ret->pause = settings[4];
    ret->inv   = settings[5];
    if (__DEBUG__)
        my_printf("[D]:\nU: %s\tL: %s\nD: %s\tR: %s\nP: %sInv:%s\n",
        ret->up, ret->left, ret->down, ret->right, ret->pause, ret->inv);
    close(fd);
    return ret;
}

settings_t *load_settings(void)
{
    settings_t *ret = malloc(sizeof(settings_t));
    char **settings;
    int fd = open("settings.csv", O_RDONLY);

    if (fd < 0)
        return NULL;
    get_next_line(fd);
    settings = my_str_to_wordtab(get_next_line(fd), ',');
    ret->WH = my_getnbr(settings[0]);
    ret->WW = my_getnbr(settings[1]);
    ret->volume = my_getnbr(settings[2]);
    ret->emitter = my_getnbr(settings[3]);
    ret->name = settings[4];
    ret->status = "menu";
    ret->keys = load_keys();
    ret->game_defined = 0;
    close(fd);
    return !ret || !settings || !ret->keys ? NULL: ret;
}