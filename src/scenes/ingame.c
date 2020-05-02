/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ingame.c
*/

#include "main.h"
#include "rpg.h"
#include "lib.h"
#include "buttons.h"
#include "scenes.h"
#include "entity.h"

void buttons_ingame(sfRenderWindow *win, int WW, int WH)
{
}
/*add_button(&g_buttons, "notif", mkf_rect((sfFloatRect)
        {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Send notif");*/

void set_movement(event_st *state, knight_s *knight)
{
    if (state->data && my_strcmp(state->data, "none"))
        knight->render.state = 1;
    if (state->data && my_strcmp(state->data, "right"))
        knight->render.state = 2;
    if (knight->render.is_attacking == 1)
        knight->render.state = 3;
    if (state->data && my_strcmp(state->data, "left"))
        knight->render.state = 4;
    if (state->data && my_strcmp(state->data, "up"))
        knight->render.state = 5;
    if (state->data && my_strcmp(state->data, "down"))
        knight->render.state = 6;
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        knight->render.is_attacking = 1;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    init_knight(&(game->knight));
    init_mob(&(game->mob));
    game->para = set_parallax();
    settings->game_defined = 1;
    return (game);
}

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
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