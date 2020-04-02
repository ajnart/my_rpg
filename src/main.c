/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** main.c
*/

#include "../src/settings/settings.h"
#include "lib.h"
#include "main.h"

asset_store_t *g_assets;

settings_t *load_settings(void);

void handle_events(sfEvent evt, sfRenderWindow *win);

void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)());

void loop_ingame(sfRenderWindow *win,
    struct event_state *state, void (**loop)())
{
    sfSprite *cursor = sfSprite_create();

    sfSprite_setTexture(cursor, find_asset_byname("arrow.png")->asset_store.texture,
        sfTrue);
    sfSprite_destroy(cursor);
    if (state->type == sfEvtMouseButtonPressed
        && state->data && my_strcmp(state->data, "back"))
        *loop = &loop_menu;
}

void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)())
{
    if (state->type == sfEvtMouseButtonPressed
        && state->data && my_strcmp(state->data, "start"))
        *loop = &loop_ingame;
    else if (state->type == sfEvtMouseButtonPressed
        && state->data && my_strcmp(state->data, "quit"))
        sfRenderWindow_close(win);
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

void perform_mainloop(sfRenderWindow *window, void (**loop)(), void (**loop_old)())
{
    sfEvent event;

    sfRenderWindow_clear(window, (sfColor){40, 40, 40, 255});
    if (sfRenderWindow_pollEvent(window, &event))
        handle_events(event, window);
    *loop_old = *loop;
    (*loop)(window, loop);
    sfRenderWindow_display(window);
}

int my_rpg(int ac, char **av, char **env)
{
    settings_t *settings = load_settings();
    if (!settings)
        return 84;
    sfRenderWindow *window = create_window("MY RPG !", 60, settings);
    void (*loop)(sfRenderWindow *,
        struct event_state *, void (**)()) = &loop_menu;
    void (*loop_old)() = NULL;
    struct event_state *state = malloc(sizeof(struct event_state));

    while (sfRenderWindow_isOpen(window))
        perform_mainloop(window, &loop, &loop_old);
    destroy_assets(g_assets);
    sfRenderWindow_destroy(window);
    return (0);
}

#ifndef __TESTS

int main(int ac, char **av, char **env)
{
    return(my_rpg(ac, av, env));
}

#endif