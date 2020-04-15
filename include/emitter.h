/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** emitter.h
*/

#ifndef __CSFML__
#define __CSFML__

#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Window.h"

#endif

#ifndef __EMITTER__
#define __EMITTER__

typedef struct color_s
{
    int r;
    int g;
    int b;
}color_t;

typedef struct particle_elem_s
{
    sfVector2f *initial_pos;
    sfVector2f *pos;
    sfVector2f *dir;
    sfClock *time_alive;
    sfColor color;

    float size;
    int initial_size;
    int range;
    int form;
    long int life_time;

    struct particle_elem_s *next;
    struct particle_elem_s *prev;
}particle_node;

typedef struct emitter_struct
{
    int nb;
    int range;
    int is_attenuation;
    int max_size;

    long int life_time;

    char form[2];

    sfClock *ref;

    sfColor color;
    color_t random_color;

    sfCircleShape *circle;
    sfRectangleShape *square;

    particle_node *particles_first;
}emitter_t;

// Emitter cleanup.
void emitter_cleanup(emitter_t *emitter);
void emitter_interrup(emitter_t *emitter);
// Creates an emitter_t.
emitter_t *emitter_create(int number_per_sec);
// Needs an emitter_t. Initialised by emitter_create()
void display_particles(sfRenderWindow *win,
    emitter_t *emitter, sfVector2i mouse);
void draw_emitter(sfRenderWindow *win, emitter_t *emitter);
void particles_set_form(emitter_t *emitter, char *form);
void particles_set_color(emitter_t *emitter, int red, int green, int blue);

#endif