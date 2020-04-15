/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** main.c
*/

#include "../src/settings/settings.h"
#include "lib.h"
#include "main.h"
#include "rpg.h"

void cleanup(sfRenderWindow *win, asset_store_t *assets, settings_t *set);

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

int my_rpg(int ac, char **av, char **env)
{
    g_assets = load_assets();
    settings = load_settings();
    if (!settings)
        return 84;
    sfRenderWindow *window = create_window("MY RPG !", 60, settings);
    void (*loop)(sfRenderWindow *, event_st *, void (**)()) = &loop_menu;
    void (*loop_old)() = NULL;
    event_st *state = malloc(sizeof(event_st));
    state->data = "none";
    state->type = sfEvtJoystickButtonReleased;

    while (sfRenderWindow_isOpen(window))
        perform_loops(window, &loop, &loop_old, state);
    cleanup(window, g_assets, settings);
    return (0);
}

#ifndef __TESTS

int main(int ac, char **av, char **env)
{
    return(my_rpg(ac, av, env));
}

#endif