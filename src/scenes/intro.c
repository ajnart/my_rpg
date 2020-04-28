/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intro.c
*/

#include "main.h"

void play_intro(sfRenderWindow *window)
{
    int i = 0;
    sfTexture *t = sfTexture_createFromFile("./assets/intro/mega.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfMusic *music = sfMusic_createFromFile("./assets/intro/intro.wav");
    sfIntRect rect = {0, 0, 960, 540};
    sfSprite_setPosition(sprite, (sfVector2f){settings->WW/2, settings->WH/2});
    sfSprite_setOrigin(sprite, (sfVector2f){480, 270});
    sfRenderWindow_setFramerateLimit(window, 90);
    sfSprite_setTexture(sprite, t, sfTrue);
    sfMusic_setVolume(music, settings->volume);
    sfMusic_play(music);
    while (i < 264) {
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        if (rect.left == 11520) {
            rect.top += 540;
            rect.left = 0;
        }
        rect.left += 960;
        i++;
    }
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfTexture_destroy(t);
    sfRenderWindow_setFramerateLimit(window, 60);
    return;
}