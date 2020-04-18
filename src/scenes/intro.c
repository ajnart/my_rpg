/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intro.c
*/

#include "main.h"

int play_intro(sfRenderWindow *window)
{
    int i = 0;
    sfTexture *t = sfTexture_createFromFile("./assets/intro/mega.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfMusic *music = sfMusic_createFromFile("./assets/intro/EAE.ogg");
    sfIntRect rect = {0, 0, 650, 450};
    sfRenderWindow_setFramerateLimit(window, 25);
    sfSprite_setTexture(sprite, t, sfTrue);
    sfMusic_play(music);
    while (i < 80) {
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        if (rect.left == 12000) {
            rect.top += 450;
            rect.left = 0;
        }
        rect.left += 600;
        i ++;
    }
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfTexture_destroy(t);
    sfRenderWindow_setFramerateLimit(window, 60);
    return 0;
}