/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** print_message.c
*/

#include "../../include/graphlib.h"
#include "../../include/lib.h"

void add_rect_text(sfRenderWindow *win, rect_text *info)
{
    sfFloatRect bounds;
    sfVector2f position;

    sfText_setString(info->text, info->str);
    sfText_setFont(info->text, find_asset_byname("font.ttf")->asset_store.font);
    sfText_setColor(info->text, info->fill);
    sfText_setCharacterSize(info->text,
    (sfRectangleShape_getSize(info->render).x +
        sfRectangleShape_getSize(info->render).y) / 20 * info->size / 10);
    bounds = sfText_getLocalBounds(info->text);
    sfText_setOrigin(info->text, (sfVector2f)
        {bounds.width/2, bounds.height/10*12});
    sfRenderWindow_drawRectangleShape(win, info->render, NULL);
    bounds = sfRectangleShape_getLocalBounds(info->render);
    position = sfRectangleShape_getPosition(info->render);
    sfText_setPosition(info->text, (sfVector2f){position.x+bounds.width/2,
        position.y+bounds.height/2});
    sfRenderWindow_drawText(win, info->text, NULL);
}

void print_message(char *str, sfRenderWindow *win, float size,
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