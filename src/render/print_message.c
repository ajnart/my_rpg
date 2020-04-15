/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_message.c
*/

#include "lib.h"
#include "../assets/asset_loader.h"

void print_message(char *str, sfRenderWindow *win, char *s_ft, sfVector2f info)
{
    sfFont *font = find_asset_byname(s_ft)->asset_store.font;
    static sfBool init = sfFalse;
    static sfText *text;
    if (!init) {
        text = sfText_create();
        init = sfTrue;
    }
    sfText_setFont(text, (const sfFont*)font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 0.04 * sfRenderWindow_getSize(win).x);
    sfText_setPosition(text, (sfVector2f){info.x, info.y});
    sfRenderWindow_drawText(win, text, NULL);
    if (my_strncmp(str, "cleanup", 7)) {
        sfText_destroy(text);
    }
}