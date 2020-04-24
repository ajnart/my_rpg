/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** load_settings.c
*/

#include <fcntl.h>
#include "buttons.h"
#include "lib.h"
#include "rpg.h"

sfKeys_t *load_keys()
{
    sfKeys_t *ret = malloc(sizeof(sfKeys_t));
    int fd = open("settings.csv", O_RDONLY);
    if (fd < 0)
        return NULL;
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    char **settings = my_str_to_wordtab(get_next_line(fd), ',');
    ret->up    = settings[0];
    ret->left  = settings[1];
    ret->down  = settings[2];
    ret->right = settings[3];
    ret->pause = settings[4];
    ret->inv = settings[5];
    my_printf("[KEYS]:\nup: %s\tleft: %s\ndown: %s\tright: %s\npause: %s\tinv\
    :%s\n", ret->up, ret->left, ret->down, ret->right, ret->pause, ret->inv);
    close(fd);
    return ret;
}

settings_t *load_settings(void)
{
    settings_t *ret = malloc(sizeof(settings_t));
    int fd = open("settings.csv", O_RDONLY);
    if (fd < 0)
        return NULL;
    get_next_line(fd);
    char **settings = my_str_to_wordtab(get_next_line(fd), ',');

    ret->WH = my_getnbr(settings[0]);
    ret->WW = my_getnbr(settings[1]);
    ret->volume = my_getnbr(settings[2]);
    ret->emitter = my_getnbr(settings[3]);
    ret->name = settings[4];
    ret->status = "Main menu";
    ret->keys = load_keys();
    if (!ret || fd < 0 || !settings || !ret->WH || !ret->WW ||
    !ret->volume) {
        close(fd);
        return NULL;
    }
    close(fd);
    return ret;
}