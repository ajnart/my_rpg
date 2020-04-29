/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** main.c
*/

#include "main.h"
#include "emitter.h"
#include "rpg.h"
#include "scenes.h"
#include "lib.h"

emitter_t *emitter_setup(int max_div, int number_div, int range_div)
{
    emitter_t *ret = emitter_create((settings->WW + settings->WH) / number_div);
    if (!ret)
        return NULL;
    ret->max_size = (settings->WW + settings->WH) / max_div;
    particles_set_color(ret, -1, -1, 255);
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

void send_notifs(sfRenderWindow *win, char *str, char *substr);

int my_rpg(int ac, char **av, char **env)
{
    g_assets = load_assets();
    settings = load_settings();
    emitter_t *emitter = emitter_setup(150, 4, 10);
    if (!settings || !g_assets || !emitter)
        return 84;
    sfRenderWindow *window = create_window("Knight Of Boulogne !", 60,
    settings);
    // play_intro(window);
    void (*loop)(sfRenderWindow *, event_st *, void (**)()) = &loop_menu;
    void (*loop_old)() = NULL;
    event_st *state = malloc(sizeof(event_st));
    state->data = "none";
    state->type = sfEvtJoystickButtonReleased;
    while (sfRenderWindow_isOpen(window))
        perform_loops(window, &loop, &loop_old, state, emitter);
    cleanup(window, g_assets, settings);
    return (0);
}

#ifndef __TESTS

char *my_sprintf(char *str, ...);

int main(int ac, char **av, char **env)
{
    int i = 6000;
    char *t = "teube";
    printf("Il fait %d degrés dehors\n", i);
    char *ret = my_sprintf("Il fait chaud dehors, %d degrés, j'ai une grosse %s test\n", i, t);
    printf("Contenu du buffer : %s\n", ret);
    return 0;
    // return (my_rpg(ac, av, env));
}

#endif