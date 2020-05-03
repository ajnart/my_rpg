/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save_and_quit.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rpg.h"
#include "lib.h"
#include "entity.h"
#include <unistd.h>

void save_and_quit(sfRenderWindow *win, game_t *game)
{
    int w = 0;
    int fd = open(my_sprintf("%s.sav", settings->name), O_CREAT |
        O_WRONLY | O_TRUNC, 777);
    if (fd < 0)
        my_printf("File could not be written.\n");
    char *buffer = my_sprintf("%d:%d:%d:%d:%d:%d\nsavedata\n",
        game->knight.stats.health,
        game->knight.stats.gold,
        game->knight.stats.maxhealth,
        game->knight.stats.strength,
        game->knight.stats.luck,
        game->knight.stats.mobility);
    if (__DEBUG__)
        my_printf("[D] Saving info :\n%s\n", buffer);
    w = write(fd, buffer, my_strlen(buffer));
    close(fd);
    sfRenderWindow_close(win);
}