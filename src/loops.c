/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loops.c
*/

#include "rpg.h"
#include "lib.h"
#include "graphlib.h"
#include "main.h"

settings_t *settings;

void perform_loops(sfRenderWindow *window, void (**loop)(),
    void (**loop_old)(), event_st *state)
{
    sfEvent event;
    sfRenderWindow_clear(window, (sfColor){40, 40, 40, 255});
    if (sfRenderWindow_pollEvent(window, &event))
        handle_events(event, window, state);
    *loop_old = *loop;
    (*loop)(window, loop);
    sfRenderWindow_display(window);
}

void loop_menu(sfRenderWindow *win, event_st *state, void (**loop)())
{
    static int frame = 0;
    my_printf("Current frame : %d\n", frame);
    frame ++;
    play_music(win, "assets/music.ogg", settings);
    print_message("Eat my fucking ass", win,
    find_asset_byname("font.ttf")->asset_store.font,
    (sfVector3f){settings->WH/2, settings->WW/2 , settings->RATIO * 20});
}

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
{
}