/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** cleanup.c
*/

#include "main.h"
#include "rpg.h"
#include "../events/buttons.h"

void destroy_assets(asset_store_t *store)
{
    asset_store_t *focused = store;
    asset_store_t *next = store->next;

    while (focused) {
        switch (focused->type)
        {
        case T_TEXTURE:
            sfTexture_destroy(focused->asset_store.texture);
            break;
        case T_FONT:
            sfFont_destroy(focused->asset_store.font);
            break;
        case T_SOUND:
            sfSoundBuffer_destroy(focused->asset_store.sound);
            break;
        default:
            break;
        }
        free(focused->name);
        free(focused);
        focused = next;
        if (next)
            next = next->next;
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

void cleanup(sfRenderWindow *win, asset_store_t *assets, settings_t *set)
{
    print_message("cleanup", win, "font.ttf",
        (sfVector2f){0, 0}, sfWhite);
    sfRenderWindow_close(win);
    destroy_assets(g_assets);
    destroy_buttons(&g_buttons);
    printf("%c[1;33m",27);
    printf("Fin du my_rpg. Merci d'avoir joué 💗\n");
    printf("%c[0;33m",27);
    free(settings);
    free(g_buttons);
}