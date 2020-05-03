/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** cleanup.c
*/

#include "main.h"
#include "rpg.h"
#include "buttons.h"
#include "lib.h"
#include <stdarg.h>

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

void destroy_settings(settings_t *s)
{
    if (!my_strcmp(settings->name, "noob"))
        mult_free(7, s->keys->down, s->keys->up, s->keys->inv, 
            s->keys->pause, s->keys->right, s->keys->left, s->name);
    free(s->keys);
}

void cleanup(sfRenderWindow *w, asset_store_t *a, settings_t *s, emitter_t *e)
{
    sfRenderWindow_close(w);
    destroy_settings(s);
    destroy_assets(a);
    emitter_cleanup(e);
    destroy_buttons(&g_buttons);
    my_printf("%c[1;33m",27);
    my_printf("End of my_rpg. Thanks for playing 💗\n");
    my_printf("%c[0;33m",27);
    free(settings);
    free(g_buttons);
}