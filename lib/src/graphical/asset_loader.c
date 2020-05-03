/*
** EPITECH PROJECT, 2019
** WORLD
** File description:
** Dynamic assets loader
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/graphlib.h"
#include "../../include/lib.h"

#define PNG (6383219704)
#define OGG (6383226913)
#define WAV (6383218384)
#define JPG (6383213236)
#define TTF (6383224257)

void destroy_assets(asset_store_t *store)
{
    asset_store_t *focused = store;
    asset_store_t *next = store->next;

    while (focused->type) {
        switch (focused->type) {
        case T_TEXTURE: sfTexture_destroy(focused->asset_store.texture);
            break;
        case T_FONT: sfFont_destroy(focused->asset_store.font);
            break;
        case T_MUSIC: sfMusic_destroy(focused->asset_store.music);
            break;
        case T_SOUND: sfSoundBuffer_destroy(focused->asset_store.sound);
            break;
        default: break; }
        free(focused->name);
        free(focused);
        focused = next;
        if (next) next = next->next;
    }
}

void asset_type_define(asset_store_t *new, const char *ext, char *filename)
{
    switch (my_hash_str(ext)) {
    case PNG : new->type = T_TEXTURE;
        new->asset_store.texture = sfTexture_createFromFile(filename, NULL);
        break;
    case OGG: new->type = T_MUSIC;
        new->asset_store.music = sfMusic_createFromFile(filename);
        break;
    case WAV: new->type = T_SOUND;
        new->asset_store.sound = sfSoundBuffer_createFromFile(filename);
        break;
    case TTF: new->type = T_FONT;
        new->asset_store.font = sfFont_createFromFile(filename);
        break;
    case JPG: new->type = T_TEXTURE;
        new->asset_store.texture = sfTexture_createFromFile(filename, NULL);
        break;
    default: break;
    }
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
    asset_type_define(new, ext, filename);
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
    write(2, "Error: Asset not found. Prolly segfaulting rn..\n", 48);
    return (NULL);
}
