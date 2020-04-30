/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intro.c
*/

#include "main.h"
#include "rpg.h"

void while_intro(sfRenderWindow *window, int i,
    sfSprite *sprite, sfIntRect rect)
{
    sfEvent event;

    while (i < 264) {
        while (sfRenderWindow_pollEvent(window, &event))
            if ((int)event.type == sfEvtMouseButtonPressed)
                i = 264;
        sfRenderWindow_clear(window, sfBlack);
        print_message("Press left click to skip", window,
            "droid.ttf", (sfVector3f){settings->WW/2, settings->WH*0.9, 1});
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
}

void play_intro(sfRenderWindow *window)
{
    int i = 0;
    sfTexture *t = sfTexture_createFromFile("./assets/intro/mega.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfMusic *music = sfMusic_createFromFile("./assets/intro/intro.wav");
    sfIntRect rect = {0, 0, 960, 540};

    sfSprite_setPosition(sprite, (sfVector2f){settings->WW/2, settings->WH/2});
    sfSprite_setOrigin(sprite, (sfVector2f){480, 270});
    sfSprite_setTexture(sprite, t, sfTrue);
    sfMusic_setVolume(music, settings->volume);
    sfMusic_play(music);
    while_intro(window, i, sprite, rect);
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfTexture_destroy(t);
}