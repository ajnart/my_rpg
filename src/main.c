/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** main.c
*/

#include "emitter.h"
#include "rpg.h"
#include "scenes.h"
#include "lib.h"
#include "main.h"

emitter_t *emitter_setup(int max_div, int number_div,
    int range_div, sfVector3f color)
{
    emitter_t *ret = emitter_create((settings->WW + settings->WH) / number_div);
    if (!ret)
        return NULL;
    ret->max_size = (settings->WW + settings->WH) / max_div;
    particles_set_color(ret, color.x, color.y, color.z);
    particles_set_form(ret, "square");
    ret->life_time = 1000000;
    ret->range = (settings->WW + settings->WH) / range_div;
    ret->color.a = 200;
    return ret;
}

sfRenderWindow *create_window(char *title, int framerate, settings_t *settings)
{
    sfVideoMode video_mode;
    sfRenderWindow *window;
    video_mode.width = settings->WW;
    video_mode.height = settings->WH;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, title, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, framerate);
    return (window);
}

void play_intro(sfRenderWindow *window);

settings_t *load_settings(void);

int my_rpg(int ac, char **av, char **env)
{
    settings = load_settings();
    g_assets = load_assets();
    void (*loop_old)() = NULL;
    event_st *state = malloc(sizeof(event_st));
    sfRenderWindow *window = create_window("Knight Of Boulogne!", 60, settings);
    void (*loop)(sfRenderWindow *, event_st *, void (**)(), game_t *)
    = &loop_menu;
    emitter_t *emitter = emitter_setup(200, 4, 20, (sfVector3f){255, -1, 255});

    if (!settings || !g_assets || !emitter)
        return 84;
    play_intro(window);
    state->data = "none";
    state->type = sfEvtJoystickButtonReleased;
    while (sfRenderWindow_isOpen(window))
        perform_loops(window, &loop, &loop_old, state, emitter);
    cleanup(window, g_assets, settings, emitter);
    return (0);
}

#ifndef __TESTS

int main(int ac, char **av, char **env)
{
    return (my_rpg(ac, av, env));
}

#endif