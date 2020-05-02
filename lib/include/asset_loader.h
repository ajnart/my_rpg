/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** asset_store.h
*/

#ifndef __ASSET_STORE_H
#define __ASSET_STORE_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <dirent.h>

typedef enum { T_TEXTURE, T_FONT, T_SOUND, T_MUSIC } asset_type_t;

typedef struct event_state {
    sfEventType type;
    char *data;
} event_st;

typedef struct asset_node {
    asset_type_t type;
    char *name;
    union
    {
        sfTexture *texture;
        sfFont *font;
        sfSoundBuffer *sound;
        sfMusic *music;
    } asset_store;
    struct asset_node *next;
} asset_store_t;

asset_store_t *g_assets;

asset_store_t *load_assets(void);

void destroy_assets(asset_store_t *);

asset_store_t *find_asset_byname(char const *);

char *get_asset_fullpath(char *filename);

#endif //__ASSET_STORE_H

