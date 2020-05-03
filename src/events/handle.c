/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle.c
*/

#include "event_handler.h"
#include "lib.h"
#include "buttons.h"
#include "scenes.h"

void hdl_key(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    if (evt.key.code == sfKeyM)
        settings->emitter = settings->emitter == 0 ? 1 : 0;
    if ((char)evt.text.unicode + 65 == settings->keys->up[0])
        state->data = "up";
    if ((char)evt.text.unicode + 65 == settings->keys->left[0])
        state->data = "left";
    if ((char)evt.text.unicode + 65 == settings->keys->down[0])
        state->data = "down";
    if ((char)evt.text.unicode + 65 == settings->keys->right[0])
        state->data = "right";
    if ((char)evt.text.unicode + 65 == settings->keys->inv[0])
        state->data = "inv";
    if ((char)evt.text.unicode + 65 == settings->keys->pause[0] ||
        evt.key.code == sfKeyEscape)
        state->data = "paused";
}

void hdl_close(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    sfRenderWindow_close(win);
}

void hdl_released(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    state->data = "none";
}

void hdl_click(sfEvent evt, sfRenderWindow *win, event_st *state)
{
    sfVector2f mp = { .x = evt.mouseButton.x, .y = evt.mouseButton.y };

    state->type = evt.type;
    state->data = get_button_selected(g_buttons, mp);
}