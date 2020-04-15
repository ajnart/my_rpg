/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** buttons.c
*/

#include "buttons.h"
#include "lib.h"
#include "../loops.h"
#include "../render/render.h"

void scene_btn_loader(void (*loop)())
{
    if (g_buttons)
        destroy_buttons(&g_buttons);
    if (loop == &loop_menu) {
        add_button(&g_buttons, "quit", create_full_rect(
            (sfFloatRect){.left = settings->WW/4, .top = settings->WH/8,
            .width = settings->WW/2, .height = settings->WH/6}, NULL, sfRed), "Quit game");
        add_button(&g_buttons, "options", create_full_rect(
            (sfFloatRect){.left = settings->WW/2, .top = settings->WH/2,
            .width = settings->WW/2, .height = settings->WH/6}, NULL, sfBlue), "Options");
    }
}

void add_button(button_store_t **store, char *id,
    sfRectangleShape *render, char *str)
{
    button_store_t *newbtn = malloc(sizeof(button_store_t));
    sfFloatRect bounds;
    static sfBool init = sfFalse;
    static sfText *text;
    if (!init) {
        text = sfText_create();
        init = sfTrue;
    }
    newbtn->next = *store;
    newbtn->render = render;
    newbtn->normal = sfRectangleShape_getFillColor(render);
    newbtn->btn_id = id;
    sfText_setString(text, str);
    sfText_setFont(text, find_asset_byname("font.ttf")->asset_store.font);
    sfText_setColor(text,
        sfColor_toInteger(newbtn->normal) > 0xFFAAAAAA?sfBlack:sfWhite);
    sfText_setCharacterSize(text, 32 * settings->WW / 800 );
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
        if (sfFloatRect_contains(&select, pos.x, pos.y)) {
            // my_printf("Got a button...\n"); // ! Debug
            return (lookup->btn_id);
        }
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

void destroy_buttons(button_store_t **store)
{
    button_store_t *focus = *store;
    button_store_t *next = *store;

    while (focus) {
        next = focus->next;
        if (focus->render)
            sfRectangleShape_destroy(focus->render);
        free(focus);
        focus = next;
    }
    *store = NULL;
}