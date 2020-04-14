/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_message.c
*/

#include "../../include/graphlib.h"
#include "../../include/lib.h"

void print_message(char *str, sfRenderWindow *win, sfFont *font,
    sfVector3f info)
{
    static sfBool init = sfFalse;
    static sfText *text;
    sfFont *font_test = sfFont_createFromFile("./assets/font.ttf"); 
    if (!init) {
        text = sfText_create();
        init = sfTrue;
    }
    sfText_setFont(text, (const sfFont*)font_test);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, info.z);
    sfText_setPosition(text, (sfVector2f){info.x, info.y});
    sfRenderWindow_drawText(win, text, NULL);
    if (my_strncmp(str, "cleanup", 7)) {
        sfText_destroy(text);
    }
}