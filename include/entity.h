/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** entities.h
*/


#ifndef ENTITY_H_
#define ENTITY_H_

#include "rpg.h"

//? Knight

typedef struct knight_render {
    int state;
    int state_frame;
    int is_attacking;
    sfIntRect rect_i;
    sfIntRect rect_w;
    sfIntRect rect_a;
    sfVector2f position;
    sfSprite *sprite;
    sfClock *clock;
} knight_render;

typedef struct knight_stats {
    int health;
    int gold;
    int maxhealth;
    int strenght;
    int luck;
    int mobility;
} knight_stats;

typedef struct knight_struct {
    struct knight_render render;
    struct knight_stats stats;
} knight_s;

//? Mob

typedef struct mob_t {
    int state;
    sfIntRect rect_i;
    sfIntRect rect_a;
    sfVector2f position;
    sfSprite *sprite;
    sfClock *clock;
    struct mob_t *next;
} mob_s;

void init_mob(mob_s **mob);
void draw_mob(sfRenderWindow *win, mob_s *mob);
void move_mob(mob_s *mob, int way);

//? Parallax

typedef struct parallax {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int speed;
    struct parallax *next;
} t_para;

//? Game

typedef struct game_t {
    knight_s knight;
    mob_s *mob;
    t_para *para;
} game_t;

// ? Knight

void draw_knight(sfRenderWindow *win, knight_s *knight, game_t *game);
void draw_knight_translate(sfRenderWindow *win, knight_s *knight, int way);
void move_knight(game_t *game, int way);
void draw_knight_walking(sfRenderWindow *win, knight_s *knight, int way);
void init_knight(knight_s *knight);

t_para *set_parallax(void);
void draw_parallax(sfRenderWindow *win, game_t *game, event_st *state,
sfVector2f pos);

#endif /* ENTITY_H_ */