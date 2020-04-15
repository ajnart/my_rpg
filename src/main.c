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
#include "emitter.h"

void cleanup(sfRenderWindow *win, asset_store_t *assets, settings_t *set);

emitter_t *emitter_setup(int max_div, int number_div, int range_div)
{
    emitter_t *ret = emitter_create((settings->WW + settings->WH) / number_div);
    if (!ret)
        return NULL;
    ret->max_size = (settings->WW + settings->WH) / max_div;
    particles_set_color(ret, -1, -1, 255);
    particles_set_form(ret, "square");
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

int my_rpg(int ac, char **av, char **env)
{
    g_assets = load_assets();
    settings = load_settings();
    emitter_t *emitter = emitter_setup(100, 4, 10);
    if (!settings || !g_assets || !emitter)
        return 84;
    sfRenderWindow *window = create_window("MY RPG !", 60, settings);
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

int main(int ac, char **av, char **env)
{
    return(my_rpg(ac, av, env));
}

#endif


// int main(int argc, char const *argv[])
// {
//     sfVideoMode mode = {800, 600, 32};
//     sfRenderWindow *window;
//     sfEvent event;
//     emitter_t *emitter = emitter_create(600);
//     emitter->max_size = 15;
//     particles_set_color(emitter, 255, -1, -1);
//     particles_set_form(emitter, "square");
//     emitter->range = 255;
//     emitter->color.a = 200;
//     window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
//     int ended = 0;
//     if (!window)
//         return 84;
//     while (sfRenderWindow_isOpen(window))
//     {

//         sfRenderWindow_clear(window, sfBlack);
//         if (ended == 0)
//         {
//             display_particles(window, emitter, sfMouse_getPositionRenderWindow(window));
//         }
        
//         /* Process events */
//         while (sfRenderWindow_pollEvent(window, &event))
//         {
//             /* Close window : exit */
//             if (event.type == sfEvtClosed)
//                 sfRenderWindow_close(window);
//             if (event.type == sfEvtKeyPressed) {
//                 emitter_interrup(emitter);
//                 ended = ended == 0 ?  1 : 0;
//             }
//         };
//         sfRenderWindow_display(window);
//     }
//     return 0;
// }