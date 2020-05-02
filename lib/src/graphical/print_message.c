/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_message.c
*/

#include "../../include/graphlib.h"
#include "../../include/lib.h"

void print_message(char *str, sfRenderWindow *win, int size,
    sfVector3f info)
{
    sfFloatRect bounds;
    static sfBool init = sfFalse;
    static sfText *text;
    if (!init) {
        text = sfText_create();
        init = sfTrue;
    }
    bounds = sfText_getLocalBounds(text);
    if (info.z == 0)
        sfText_setOrigin(text, (sfVector2f) {bounds.width/2, bounds.height/2});
    else
        sfText_setOrigin(text, (sfVector2f){0, 0});
    sfText_setFont(text, find_asset_byname("font.ttf")->asset_store.font);
    sfText_setString(text, str);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, size * 0.01 * (settings->WH + settings->WW));
    sfText_setPosition(text, (sfVector2f){info.x, info.y});
    sfRenderWindow_drawText(win, text, NULL);
}