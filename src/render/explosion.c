/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** explosion.c
*/

#include "main.h"
#include "emitter.h"
#include "lib.h"
#include "rpg.h"

emitter_t *emitter_setup(int max_div, int number_div, int range_div);

void explosion(sfRenderWindow *win , sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    print_message("Switching to settings...", win, "font.ttf",
        (sfVector3f){settings->WW*0.4, settings->WH*0.7, 0});
    sfRenderWindow_display(win);
    sfTime time;
    time.microseconds = 400000;
    sfSleep(time);
}