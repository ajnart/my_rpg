/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** notification.c
*/

#include "rpg.h"
#define WW (settings->WW)
#define WH (settings->WH)

void update_notifs(sfRenderWindow *win, int request)
{
    static int lifespan;

    if (request > 0)
        lifespan = request;
    else if (lifespan > 0)
        send_notifs(win, NULL, NULL, lifespan);
    lifespan -= 1;
}

void send_notifs(sfRenderWindow *win, char *str, char *substr, int lifeleft)
{
    static sfSound *s;
    static char *string;
    static char *substring;

    if (str && substr || !s) {
        string = str;
        substring = substr;
        s = sfSound_create();
        sfSound_setBuffer(s,
            find_asset_byname("notification.ogg")->asset_store.sound);
        sfSound_play(s);
        update_notifs(win, lifeleft);
    }
    else {
        print_message(string, win, (float)1.2, (sfVector3f){WH*0.6, 0, 5});
        print_message(substring, win, (float)1, (sfVector3f){WH*0.6, 0, 5});
    }
    if (lifeleft == 0)
        sfSound_destroy(s);
}