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
#include "parallax.h"
#include "../entitites/knight.h"

void buttons_ingame(sfRenderWindow *win, int WW, int WH)
{
    /*add_button(&g_buttons, "notif", create_full_rect((sfFloatRect)
            {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Send notif");*/
}

void init_knight(knight_s *knight)
{
    knight->render.sprite = sfSprite_create();
    knight->render.position =
        (sfVector2f){settings->WW * 0.1, settings->WH * 0.92};
    knight->render.state = 1;
    knight->render.rect_i = (sfIntRect){0, 0, 64, 64};
    knight->render.rect_w = (sfIntRect){0, 0, 64, 64};
    knight->render.rect_a = (sfIntRect){0, 0, 64, 64};
    knight->render.is_attacking = 0;
    knight->render.clock = sfClock_create();
    sfSprite_setOrigin(knight->render.sprite, (sfVector2f){32, 32});
    sfSprite_setTexture(knight->render.sprite,
        find_asset_byname("Idle.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(knight->render.sprite, knight->render.rect_i);
    sfSprite_setScale(knight->render.sprite,
    (sfVector2f){(double)settings->WW / 400, (double)settings->WH / 400});
}

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

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
{
    static t_para *parallax;
    static knight_s knight;

    if (!parallax) {
        init_knight(&knight);
        parallax = set_parallax();
    }
    set_movement(state, &knight);
    draw_parallax(win, parallax, state);
    draw_knight(win, &knight);
    update_notifs(win, 0);
    settings->status = "Game";
    print_message(settings->status, win, 1,
        (sfVector3f){settings->WW * 0.5, settings->WH * 0.1, 0});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        if (my_strcmp(state->data, "notif")) {
            send_notifs(win, "You have won", "Golds", 60);
            state->data = NULL;
        }
    }
}