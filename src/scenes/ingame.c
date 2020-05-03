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

void draw_inventory(sfRenderWindow *win, game_t *game)
{
    int WW = settings->WW;
    int WH = settings->WH;
    sfVector2f scale = {0.04, 0.04};
    sfVector2f origin = {995, 1000};
    sfVector2f pos = {settings->WW*0.9, WW*0.2};

    if (game->knight.render.inv == 1) {
        sfSprite_setTexture(game->knight.render.gold,
        find_asset_byname("gold.png")->asset_store.texture, sfTrue);
        sfSprite_setOrigin(game->knight.render.gold, origin);
        sfSprite_setScale(game->knight.render.gold, scale);
        sfSprite_setPosition(game->knight.render.gold, pos);
        sfRenderWindow_drawSprite(win, game->knight.render.gold, NULL);
        print_message(my_sprintf("%d", game->knight.stats.gold), win,
        (float)2, (sfVector3f){pos.x + 80, pos.y, 0});
    }
}

void set_movement(sfRenderWindow *win, event_st *state, knight_s *knight)
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
    if (state->data && my_strcmp(state->data, "inv"))
        knight->render.inv = 1;
    else
        knight->render.inv = 0;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    init_knight(&(game->knight));
    init_mob(&(game->mob));
    init_npc(&(game->npc));
    init_boss(&(game->boss));
    game->para = set_parallax();
    settings->game_defined = 1;
    game->view = sfView_create();
    sfView_setSize(game->view, (sfVector2f){400, 400});
    return (game);
}

void loop_ingame(sfRenderWindow *win, event_st *state,
    void (**loop)(), game_t *game)
{
    set_movement(win, state, &(game->knight));
    draw_parallax(win, game, state, game->knight.render.position);
    draw_npc(win, &(game->npc), state, game);
    draw_mob(win, game->mob, game->knight.render.position.x, game);
    draw_knight(win, &(game->knight), game);
    draw_boss(win, &(game->boss), game);
    draw_inventory(win, game);
    if (state->type == 10 && state->data) {
        if (my_strcmp(state->data, "paused")) {
            *loop = &loop_settings;
            settings->paused = 1;
        }
    }
    if (game->knight.stats.health <= 0)
        dead_knight(win);
}