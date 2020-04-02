/*
** EPITECH PROJECT, 2019
** WORLD
** File description:
** Dynamic assets loader
*/

#include <unistd.h>
#include "asset_loader.h"
#include "main.h"
#include "lib.h"

void destroy_assets(asset_store_t *store)
{
    asset_store_t *focused = store;
    asset_store_t *next = store->next;

    while (focused) {
        if (focused->type == T_TEXTURE)
            sfTexture_destroy(focused->asset_store.texture);
        else if (focused->type == T_FONT)
            sfFont_destroy(focused->asset_store.font);
        else if (focused->type == T_SOUND)
            sfSoundBuffer_destroy(focused->asset_store.sound);
        free(focused->name);
        free(focused);
        focused = next;
        if (next)
            next = next->next;
    }
}

char *get_asset_fullpath(char *filename)
{
    char *result = my_strdup("assets/");

    str_append(&result, "/");
    str_append(&result, filename);
    return (result);
}

void load_asset_fromfile(struct dirent *toload, asset_store_t **store)
{
    char *filename = get_asset_fullpath(toload->d_name);
    char *ext = toload->d_name + my_strlen(toload->d_name) - 4;
    asset_store_t *new = malloc(sizeof(asset_store_t));

    if (toload->d_name[0] == '.' || my_strlen(toload->d_name) < 5) {
        free(filename);
        free(new);
        return;
    }
    new->name = my_strdup(toload->d_name);
    if (my_strcmp(ext, ".png")) {
        new->type = T_TEXTURE;
        new->asset_store.texture = sfTexture_createFromFile(filename, NULL);
    } else if (my_strcmp(ext, ".ttf")) {
        new->type = T_FONT;
        new->asset_store.font = sfFont_createFromFile(filename);
    } else if (my_strcmp(ext, ".ogg")) {
        new->type = T_SOUND;
        new->asset_store.sound = sfSoundBuffer_createFromFile(filename);
    }
    new->next = *store;
    *store = new;
    free(filename);
}

asset_store_t *load_assets(void)
{
    DIR *scandir = opendir("assets/");
    struct dirent *toload;
    asset_store_t *ret = NULL;

    if (!scandir) {
        return (0);
    } else {
        while ((toload = readdir(scandir)))
            load_asset_fromfile(toload, &ret);
        closedir(scandir);
    }
    return (ret);
}

asset_store_t *find_asset_byname(char const *name)
{
    asset_store_t *curr = g_assets;

    while (curr) {
        if (my_strcmp(curr->name, name))
            return (curr);
        curr = curr->next;
    }
    return (NULL);
}
