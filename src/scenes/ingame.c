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

void buttons_ingame(sfRenderWindow *win, int WW, int WH)
{
    add_button(&g_buttons, "notif", create_full_rect((sfFloatRect)
            {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Send notif");
}

void send_notifs(sfRenderWindow *win, char *str, char *substr);

void update_notifs(sfRenderWindow *win, int request);

void loop_ingame(sfRenderWindow *win, event_st *state, void (**loop)())
{
    static t_para *parallax;
    if (!parallax)
        parallax = set_parallax();
    draw_parallax(win, parallax);
    update_notifs(win, 0);
    settings->status = "Game";
    print_message(settings->status, win, "font.ttf",
        (sfVector3f){settings->WW * 0.5, settings->WH * 0.1, 0});
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        if (my_strcmp(state->data, "notif")) {
            send_notifs(win, "You have won", "Zbeub");
            state->data = NULL;
        }
    }
}