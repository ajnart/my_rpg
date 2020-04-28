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

asset_store_t *g_assets;

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
    if (my_strcmp(ext, ".png") || my_strcmp(ext, ".jpg")) {
        new->type = T_TEXTURE;
        new->asset_store.texture = sfTexture_createFromFile(filename, NULL);
    } else if (my_strcmp(ext, ".ttf")) {
        new->type = T_FONT;
        new->asset_store.font = sfFont_createFromFile(filename);
    } else if (my_strcmp(ext, ".ogg")) {
        new->type = T_MUSIC;
        new->asset_store.music = sfMusic_createFromFile(filename);
    } else if (my_strcmp(ext, ".wav")) {
        new->type = T_SOUND;
        new->asset_store.sound = sfSoundBuffer_createFromFile(filename);
    }
    new->next = *store;
    *store = new;
    free(filename);
}
// TODO : Can load sounds into a soundbuffer.
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
