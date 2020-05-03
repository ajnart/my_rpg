/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** buttons.c
*/

#include "buttons.h"
#include "lib.h"
#include "rpg.h"
#include "scenes.h"

void scene_btn_loader(void (*loop)(), sfRenderWindow *win)
{
    const int WW = sfRenderWindow_getSize(win).x;
    const int WH = sfRenderWindow_getSize(win).y;

    if (g_buttons)
        destroy_buttons(&g_buttons);
    if (loop == &loop_menu)
        buttons_menu(win, WW, WH);
    if (loop == &loop_ingame)
        buttons_ingame(win, WW, WH);
    if (loop == &loop_settings)
        buttons_settings(win, WW, WH);
}

void add_button(button_store_t **store, char *id,
sfRectangleShape *render, char *str)
{
    button_store_t *newbtn = malloc(sizeof(button_store_t));
    sfFloatRect bounds;
    sfText *text = sfText_create();

    newbtn->next = *store;
    newbtn->render = render;
    newbtn->normal = sfRectangleShape_getFillColor(render);
    newbtn->btn_id = id;
    sfText_setString(text, str);
    sfText_setFont(text, find_asset_byname("font.ttf")->asset_store.font);
    sfText_setColor(text,
    sfColor_toInteger(newbtn->normal) > 0xFFAAAAAA?sfBlack:sfWhite);
    sfText_setCharacterSize(text, (sfRectangleShape_getSize(render).x +
    sfRectangleShape_getSize(render).y) / 23);
    bounds = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f) {bounds.width/2, bounds.height/10*12});
    newbtn->text = text;
    *store = newbtn;
}

char *get_button_selected(const button_store_t *store, sfVector2f pos)
{
    button_store_t *lookup = (button_store_t *)store;
    sfFloatRect select;
    while (lookup) {
        select = sfRectangleShape_getGlobalBounds(lookup->render);
        if (sfFloatRect_contains(&select, pos.x, pos.y))
            return (lookup->btn_id);
        lookup = lookup->next;
    }
    return (NULL);
}

button_store_t *get_button(const button_store_t *store, char *name)
{
    button_store_t *lookup = (button_store_t *) store;

    while (lookup) {
        if (my_strcmp(lookup->btn_id, name))
            return (lookup);
        lookup = lookup->next;
    }
    return (NULL);
}