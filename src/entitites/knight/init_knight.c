/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_knight.c
*/
#include "entity.h"
#include "lib.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void init_knight_fromfile(char *playername, knight_s *pl)
{
    char **tab;
    char buffer[32];
    int fd = open(my_sprintf("%s.sav", playername), O_RDONLY);

    if (__DEBUG__)
        my_printf("[D]\t %s.sav ... fd : %d\n", playername, fd);
    if (fd < 0)
        pl->stats = (struct knight_stats){100, 0, 100, 30, 1, 1};
    else {
        read(fd, buffer, 32);
        tab = my_str_to_wordtab(buffer, ':');
        pl->stats = (struct knight_stats){my_atoi(tab[0]), my_atoi(tab[1]),
        my_atoi(tab[2]), my_atoi(tab[3]), my_atoi(tab[4]), my_atoi(tab[5])};
    }
    if (__DEBUG__)
        my_printf("[D]\tLoaded stats:\nG:%d\t:H%d\tL:%d\tMH:%d\tM:%d\tS:%d\n",
        pl->stats.gold, pl->stats.health, pl->stats.luck, pl->stats.maxhealth,
            pl->stats.mobility, pl->stats.strength);
    close(fd);
}

void init_knight(knight_s *knight)
{
    init_knight_fromfile(settings->name, knight);
    knight->render.sprite = sfSprite_create();
    knight->render.gold = sfSprite_create();
    knight->render.position =
        (sfVector2f){settings->WW * 0.1, settings->WH * 0.92};
    knight->render.state = 1;
    knight->render.rect_i = (sfIntRect){0, 0, 64, 64};
    knight->render.rect_w = (sfIntRect){0, 0, 64, 64};
    knight->render.rect_a = (sfIntRect){0, 0, 64, 64};
    knight->render.is_attacking = 0;
    knight->render.inv = 0;
    knight->render.clock = sfClock_create();
    sfSprite_setOrigin(knight->render.sprite, (sfVector2f){32, 32});
    sfSprite_setTexture(knight->render.sprite,
        find_asset_byname("Idle.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(knight->render.sprite, knight->render.rect_i);
    sfSprite_setScale(knight->render.sprite,
    (sfVector2f){(double)settings->WW / 400, (double)settings->WH / 400});
}