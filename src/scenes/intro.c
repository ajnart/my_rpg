/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intro.c
*/

#include "main.h"
#include "rpg.h"

void intro_particles(sfRenderWindow *win, int x, int y, emitter_t *emitter)
{
    particles_set_form(emitter, "random");
    display_particles(win, emitter, sfMouse_getPositionRenderWindow(win));
}

void while_intro(sfRenderWindow *window, sfSprite *sprite, sfIntRect rect)
{
    int i = 0;
    sfEvent event;
    emitter_t *emitter = emitter_setup(120, 30, 30, (sfVector3f){-1, 255, 255});

    for (i = 0; i < 264; i++) {
        while (sfRenderWindow_pollEvent(window, &event))
            if ((int)event.type == sfEvtMouseButtonReleased ||
                (int)event.type == sfEvtClosed)
                i = 264;
        sfRenderWindow_clear(window, sfBlack);
        print_message("Press left click to skip", window,
            (float)1, (sfVector3f){settings->WW/2, settings->WH*0.9, 1});
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        intro_particles(window, settings->WW/2, settings->WH*0.95, emitter);
        sfRenderWindow_display(window);
        if (rect.left == 11520) {
            rect.top += 540;
            rect.left = 0;
        } rect.left += 960;
    }
    emitter_cleanup(emitter);
}

void play_intro(sfRenderWindow *window)
{
    sfTexture *t = sfTexture_createFromFile("./assets/intro/mega.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfMusic *music = sfMusic_createFromFile("./assets/intro/intro.wav");
    sfIntRect rect = {0, 0, 960, 540};

    sfSprite_setPosition(sprite, (sfVector2f){settings->WW/2, settings->WH/2});
    sfSprite_setOrigin(sprite, (sfVector2f){480, 270});
    sfSprite_setTexture(sprite, t, sfTrue);
    sfMusic_setVolume(music, settings->volume);
    sfMusic_play(music);
    while_intro(window, sprite, rect);
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfTexture_destroy(t);
}