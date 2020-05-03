/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** graphlib.h
*/


#ifndef __GRAPH_LIB__
#define __GRAPH_LIB__


#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
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

typedef struct keys_struct
{
    char *up;
    char *down;
    char *left;
    char *right;
    char *pause;
    char *inv;
} sfKeys_t;

typedef struct settings_struct
{
    int WH;
    int WW;
    int volume;
    int emitter;
    char *name;
    sfKeys_t *keys;
    int game_defined;
    int paused;
} settings_t;

typedef struct rect_text {
    sfRectangleShape *render;
    sfText *text;
    char *str;
    sfColor fill;
    int size;
} rect_text;

asset_store_t *g_assets;
settings_t *settings;

/* asset_loader.c */
void destroy_assets(asset_store_t *store);
void add_rect_text(sfRenderWindow *win, rect_text *info);

// * Precalculated hases :
//  ".png" = 6383219704
//  ".ogg" = 6383218384
//  ".wav" = 6383226913
//  ".jpg" = 6383213236
//  ".ttf" = 6383224257
void asset_type_define(asset_store_t *new, const char *ext, char *filename);

void load_asset_fromfile(struct dirent *toload, asset_store_t **store);
asset_store_t *load_assets(void);
asset_store_t *find_asset_byname(char const *name);
/* asset_utils.c */
float get_elapsed_time(sfClock *clock);
char *get_asset_fullpath(char *filename);
/* mult_free.c */
void play_sound(char *sound, sfRenderWindow *win, int vol);
void mult_free(int how_much, ...);
/* print_message.c */
void print_message(char *str, sfRenderWindow *win, float size, sfVector3f info);
#endif