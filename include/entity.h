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
    int inv;
    sfIntRect rect_i;
    sfIntRect rect_w;
    sfIntRect rect_a;
    sfVector2f position;
    sfSprite *sprite;
    sfSprite *gold;
    sfClock *clock;
} knight_render;

typedef struct knight_stats {
    int health;
    int gold;
    int maxhealth;
    int strength;
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
    int life;
    int damage;
    float speed;
    int alive;
    sfIntRect rect_i;
    sfIntRect rect_a;
    sfIntRect rect_w;
    sfIntRect rect_d;
    sfVector2f position;
    sfSprite *sprite;
    sfClock *clock;
    struct mob_t *next;
} mob_s;

//? NPC

typedef struct npc_t {
    int state;
    int text;
    sfIntRect rect_i;
    sfVector2f position;
    sfSprite *sprite;
    sfClock *clock;
    sfClock *clicked;
    int game_finished;
} npc_t;

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
    npc_t npc;
    mob_s *mob;
    mob_s boss;
    t_para *para;
    sfView *view;
} game_t;

//? NPC

void init_npc(npc_t *npc);
void move_npc(npc_t *npc, int way);
void draw_npc(sfRenderWindow *win, npc_t *npc, event_st *state, game_t *game);
void draw_npc_idle(sfRenderWindow *win, npc_t *npc);

// ? Knight

int check_collision_move(game_t *game, int way);
void do_damage(mob_s *mob, knight_s *knight, int sign);

void init_knight(knight_s *knight);
void move_knight(game_t *game, int way);
void draw_knight(sfRenderWindow *win, knight_s *knight, game_t *game);
void draw_knight_idle(sfRenderWindow *win, knight_s *knight);
void draw_knight_walking(sfRenderWindow *win, knight_s *knight, int way);
void draw_knight_attacking(sfRenderWindow *win, knight_s *knight,
mob_s *mob, mob_s *boss);
void draw_knight_translate(sfRenderWindow *win, game_t *game,
knight_s *knight, int way);

// ? Parallax

t_para *set_parallax(void);
void draw_parallax(sfRenderWindow *win, game_t *game, event_st *state,
sfVector2f pos);

//? Mob

void init_mob(mob_s **mob);
void mob_aggro(mob_s *mob, int k_pos);
mob_s *delete_mob(sfRenderWindow *win, game_t *game, mob_s *mob);

void move_mob(mob_s *mob, int way);
void draw_mob(sfRenderWindow *win, mob_s *mob, int k_pos, game_t *game);
void draw_mob_idle(sfRenderWindow *win, mob_s *mob);
void draw_mob_walking(sfRenderWindow *win, mob_s *mob, int k_pos);
void draw_mob_attacking(sfRenderWindow *win, mob_s *mob, knight_s *knight);
void draw_mob_dead(sfRenderWindow *win, mob_s *mob, game_t *game);
void get_damage(knight_s *knight, mob_s *mob);

//? Boss

void move_boss(mob_s *mob, int way);
void get_damage_boss(knight_s *knight, mob_s *mob);

void init_boss(mob_s *mob);
void draw_boss_idle(sfRenderWindow *win, mob_s *mob, knight_s *knight);
void draw_boss_attacking(sfRenderWindow *win, mob_s *mob, knight_s *knight);
void draw_boss(sfRenderWindow *win, mob_s *mob, game_t *game);

void render_health_bar(sfRenderWindow *win, mob_s *mob);
game_t *init_game(void);
void save_and_quit(sfRenderWindow *win, game_t *game);
void buy_perks(sfRenderWindow *win, game_t *game, event_st *state);
void draw_inventory(sfRenderWindow *win, game_t *game);
void dead_knight(sfRenderWindow *win);

#endif /* ENTITY_H_ */