/*
** EPITECH PROJECT, 2019
** MYRPG
** File description:
** asset_store.h
*/

#ifndef __ASSET_STORE_H
#define __ASSET_STORE_H

#include <dirent.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef enum { T_TEXTURE, T_FONT, T_SOUND } asset_type_t;


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

asset_store_t *load_assets(void);

void destroy_assets(asset_store_t *);

asset_store_t *find_asset_byname(char const *);

#endif //__ASSET_STORE_H

