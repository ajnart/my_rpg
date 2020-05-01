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
    add_button(&g_buttons, "notif", create_full_rect((sfFloatRect)
            {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Send notif");
}

void init_knight(knight_s *knight)
{
    knight->render.sprite = sfSprite_create();
    knight->render.position = (sfVector2f){400, 400};
}

void draw_knight(sfRenderWindow *win, knight_s *knight);

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
{
    static t_para *parallax;
    static knight_s *knight;

    if (!parallax) {
        knight = malloc(sizeof(knight_s));
        init_knight(knight);
        parallax = set_parallax();
    }
    draw_parallax(win, parallax);
    draw_knight(win, knight);
    update_notifs(win, 0);
    settings->status = "Game";
    print_message(settings->status, win, 1,
        (sfVector3f){settings->WW * 0.5, settings->WH * 0.1, 0});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        if (my_strcmp(state->data, "notif")) {
            send_notifs(win, "You have won", "Zbeub", 60);
            state->data = NULL;
        }
    }
}