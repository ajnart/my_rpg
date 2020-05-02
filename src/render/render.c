/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** render.c
*/

#include "buttons.h"
#include "lib.h"

void set_button_hover(sfRenderWindow *win)
{
    sfVector2i mpi = sfMouse_getPositionRenderWindow(win);
    sfVector2f mp = { .x = (float) mpi.x, .y = (float) mpi.y };
    button_store_t *btn;
    sfColor color;
    char *btn_id = get_button_selected(g_buttons, mp);

    if (btn_id) {
        btn = get_button(g_buttons, btn_id);
        color = btn->normal;
        color.a -= 120;
        sfRectangleShape_setFillColor(btn->render, color);
    }
}

void set_btn_color(sfRenderWindow *win)
{
    button_store_t *lookup = g_buttons;

    while (lookup) {
        sfRectangleShape_setFillColor(lookup->render, lookup->normal);
        lookup = lookup->next;
    }
    set_button_hover(win);
}

void draw_buttons(sfRenderWindow *win, button_store_t *store)
{
    button_store_t *focus = store;
    sfVector2f position;
    sfFloatRect bounds;

    while (focus) {
        if (focus->render)
            sfRenderWindow_drawRectangleShape(win, focus->render, NULL);
        if (focus->text) {
            bounds = sfRectangleShape_getLocalBounds(focus->render);
            position = sfRectangleShape_getPosition(focus->render);
            sfText_setPosition(focus->text, (sfVector2f)
                {position.x+bounds.width/2, position.y+bounds.height/2});
            sfRenderWindow_drawText(win, focus->text, NULL);
        }
        focus = focus->next;
    }
}

sfRectangleShape *mkf_rect(sfFloatRect pos, sfTexture *tx, sfColor fill)
{
    sfRectangleShape *dest = sfRectangleShape_create();

    sfRectangleShape_setPosition(dest,
        (sfVector2f){ .x = pos.left, .y = pos.top });
    sfRectangleShape_setSize(dest,
        (sfVector2f){ .x = pos.width, .y = pos.height });
    if (tx)
        sfRectangleShape_setTexture(dest, tx, sfTrue);
    sfRectangleShape_setFillColor(dest, fill);
    return (dest);
}