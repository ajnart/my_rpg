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
        my_printf("[D]:\nU: %s\tL: %s\nD: %s\tR: %s\nP: %s\tInv:%s\n",
        ret->up, ret->left, ret->down, ret->right, ret->pause, ret->inv);
    close(fd);
    return ret;
}

settings_t *init_settings(settings_t *ret)
{
    sfKeys_t *keys = malloc(sizeof(sfKeys_t));
    keys->up    = "Z";
    keys->left  = "Q";
    keys->down  = "S";
    keys->right = "D";
    keys->pause = "P";
    keys->inv   = "I";
    ret->paused = 0;
    ret->WH = 720;
    ret->WW = 1280;
    ret->volume = 50;
    ret->emitter = 1;
    ret->name = my_strdup("noob");
    ret->keys = keys;
    ret->game_defined = 0;
    my_printf("Settings.csv not found, using default values...(ZQSD)\n");
    if (__DEBUG__) {
        my_printf("[D]:\nU: %s\tL: %s\nD: %s\tR: %s\nP: %s\tInv:%s\n",
        keys->up, keys->left, keys->down, keys->right, keys->pause, keys->inv);}
    return (ret);
}

settings_t *load_settings(void)
{
    settings_t *ret = malloc(sizeof(settings_t));
    char **settings;
    int fd = open("settings.csv", O_RDONLY);

    if (fd < 0)
        return (init_settings(ret));
    get_next_line(fd);
    settings = my_str_to_wordtab(get_next_line(fd), ',');
    ret->paused = 0;
    ret->WH = my_atoi(settings[0]);
    ret->WW = my_atoi(settings[1]);
    ret->volume = my_atoi(settings[2]);
    ret->emitter = my_atoi(settings[3]);
    ret->name = settings[4];
    ret->keys = load_keys();
    ret->game_defined = 0;
    close(fd);
    return !ret || !settings || !ret->keys ? NULL: ret;
}