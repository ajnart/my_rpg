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
    int fd = open(my_sprintf("./saves/%s.sav", settings->name),
        O_CREAT | O_RDWR);
    if (fd < 0)
        my_printf("File could not be written.\n");
    char *buffer = my_sprintf("%d:%d:%d:%d:%d:%d\nsavedata\n",
        game->knight.stats.gold,
        game->knight.stats.health,
        game->knight.stats.maxhealth,
        game->knight.stats.strength,
        game->knight.stats.luck,
        game->knight.stats.mobility);
    if (__DEBUG__)
        my_printf("[D] Saving info :\n%s\n", buffer);
    int w = write(fd, buffer, 500);
    close(fd);
    my_printf("%d\n", w);
    close(fd);
    sfRenderWindow_close(win);
}