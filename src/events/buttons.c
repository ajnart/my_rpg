/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** buttons.c
*/

#include "buttons.h"
#include "lib.h"
#include "rpg.h"

void destroy_buttons(button_store_t **store);

void scene_btn_loader(void (*loop)(), sfRenderWindow *win)
{
    const int WW = sfRenderWindow_getSize(win).x;
    const int WH = sfRenderWindow_getSize(win).y;
    sfTexture *texture = find_asset_byname("texture.jpg")->asset_store.texture;
    sfTexture_setSmooth(texture, sfTrue);
    sfContext *context = sfContext_create();
    sfContextSettings settings = sfContext_getSettings(context);
    sfTexture_setRepeated(texture, sfTrue);
    if (g_buttons)
        destroy_buttons(&g_buttons);
    if (loop == &loop_menu) {
        add_button(&g_buttons, "quit", create_full_rect((sfFloatRect)
            {WW/4, WH * 0.7, WW/2, WH/6}, texture, sfRed), "Ragequit");
        add_button(&g_buttons, "bruh", create_full_rect((sfFloatRect)
            {WW/4, WH * 0.5, WW/2, WH/6}, texture, sfColor_fromRGB(80, 80, 80)), "Bruh button");
        add_button(&g_buttons, "settings", create_full_rect((sfFloatRect)
            {WW/4, WH * 0.3, WW/2, WH/6}, texture, sfWhite), "Settings");
    }
    if (loop == &loop_ingame) {
        add_button(&g_buttons, "back", create_full_rect((sfFloatRect)
            {0, WH * 0.9, WW*0.3, WH*0.1}, NULL, sfRed), "Back to main menu");
    }
    if (loop == &loop_settings) {
        buttons_settings(win);
    }
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
        sfRectangleShape_getSize(render).y) / 20);
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