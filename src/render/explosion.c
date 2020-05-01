/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** explosion.c
*/

#include "rpg.h"
#include "lib.h"

void explosion(sfRenderWindow *win, char *str)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    sfSprite *sprite = sfSprite_create();
    sfTime time;

    print_message(my_sprintf("Loading... %s pressed...", str),
        win, 1, (sfVector3f){pos.x, pos.y, 0});
    sfRenderWindow_display(win);
    time.microseconds = 400000;
    sfSleep(time);
}