/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** notification.c
*/

#include "rpg.h"
#define WW (settings->WW)
#define WH (settings->WH)

void send_notifs(sfRenderWindow *win, char *str, char *substr)
{
    static sfSoundBuffer *sb;
    static sfSound *sound;

    if (!sb || !sound) {
    sound = sfSound_create();
    sfSound_setBuffer(sound, find_asset_byname("sound.wav")->asset_store.sound);
    }
    sfSound_play(sound);
    sfRectangleShape *main = create_full_rect((sfFloatRect){0, 0,
    WW*0.2, WH*0.04}, NULL, (sfColor){0, 50, 0, 255});
    sfRectangleShape *second = create_full_rect((sfFloatRect){0, WH*0.04,
    WW*0.2, WH*0.05}, NULL, (sfColor){20, 20, 20, 255});
    sfRenderWindow_drawRectangleShape(win, main, NULL);
    sfRenderWindow_drawRectangleShape(win, second, NULL);
    print_message(str, win, "droid.ttf", (sfVector3f){0, 0, 1});
    print_message(substr, win, "droid.ttf", (sfVector3f){0, WH*0.04, 1});
    sfRenderWindow_display(win);
    sfRectangleShape_destroy(main);
    sfRectangleShape_destroy(second);
}