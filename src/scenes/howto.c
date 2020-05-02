/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** howto.c
*/

#include "main.h"
#include "rpg.h"
#include "lib.h"
#include "buttons.h"
#include "scenes.h"
#include "entity.h"

void buttons_howto(sfRenderWindow *win, int WW, int WH)
{
    add_button(&g_buttons, "nest-page", mkf_rect((sfFloatRect)
        {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "->");
}

void loop_howto(sfRenderWindow *win, event_st *state, void (**loop)())
{
    static game_t *game;

    if (!settings->game_defined)
        game = init_game();
    set_movement(state, &(game->knight));
    draw_parallax(win, game, state, game->knight.render.position);
    draw_mob(win, game->mob);
    draw_knight(win, &(game->knight), game);
    update_notifs(win, 0);
    settings->status = "Game";
    print_message(settings->status, win, 1,
        (sfVector3f){settings->WW * 0.5, settings->WH * 0.1, 0});
    if (state->type == 10 && state->data) {
        if (my_strcmp(state->data, "paused")) {
            *loop = &loop_settings;
            settings->paused = 1;
        }
    }
}