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

void destroy_assets(asset_store_t *store)
{
    asset_store_t *focused = store;
    asset_store_t *next = store->next;

    while (focused->type) {
        switch (focused->type) {
        case T_TEXTURE: sfTexture_destroy(focused->asset_store.texture); break;
        case T_FONT: sfFont_destroy(focused->asset_store.font); break;
        case T_MUSIC: sfMusic_destroy(focused->asset_store.music); break;
        case T_SOUND: sfSoundBuffer_destroy(focused->asset_store.sound); break;
        default: break; }
        free(focused->name);
        free(focused);
        focused = next;
        if (next) next = next->next;
    }
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

void mult_free(int how_much, ...)
{
    va_list ap;
    va_start(ap, how_much);
    char *freeing = NULL;
    int i = 0;

    while (i < how_much) {
        freeing = va_arg(ap, char *);
        free(freeing);
        i++;
    }
}

void destroy_settings(settings_t *s)
{
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
    my_printf("Fin du my_rpg. Merci d'avoir joué 💗\n");
    my_printf("%c[0;33m",27);
    free(settings);
    free(g_buttons);
}