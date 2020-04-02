/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** load_settings.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lib.h"
#include "settings.h"

settings_t *load_settings(void)
{
    settings_t *ret = malloc(sizeof(settings_t));
    int fd = open("settings", O_RDONLY);
    if (fd < 0)
        return NULL;
    char **settings = my_str_to_wordtab(get_next_line(fd), ';');

    ret->WH = my_getnbr(settings[0]);
    ret->WW = my_getnbr(settings[1]);
    ret->volume = my_getnbr(settings[2]);
    if (!ret || fd < 0 || !settings || !ret->WH || !ret->WW || !ret->volume)
        return NULL;
    return ret;
}