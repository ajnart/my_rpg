/*
** EPITECH PROJECT, 2019
** include
** File description:
** particles.h
*/

#ifndef __PARTICLES__
#define __PARTICLES__

#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Window.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct color_s
{
    int r;
    int g;
    int b;
} color_t;

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
} particle_node;

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

void emitter_free(particle_node *temp);
void emitter_delete(particle_node *temp, emitter_t *emitter);
// Emitter cleanup.
void emitter_cleanup(emitter_t *emitter);
void emitter_interrup(emitter_t *emitter);
// Creates an emitter_t.
emitter_t *emitter_create(int number_per_sec);
// Needs an emitter_t. Initialised by emitter_create()
void display_particles(sfRenderWindow *win,
    emitter_t *emitter, sfVector2i mouse);
void draw_emitter(sfRenderWindow *win, emitter_t *emitter);

int get_form(emitter_t *emitter);
/* lib/src/particles/create.c */
float create_dir(void);
sfColor copy_color_particle(sfColor color, color_t random);
particle_node *init_emitter_node(emitter_t *emitter, sfVector2i *mouse);
void add_node(emitter_t *emitter, sfRenderWindow *win,
    sfVector2i mouse, int nb);
/* lib/src/particles/display.c */
void manage_first_clock(emitter_t *emitter);
int is_delay(emitter_t *emitter);
/* lib/src/particles/init.c */
void set_particle_color(emitter_t *emitter, particle_node *temp, long int sec);
sfVector2f *init_pos_particles(float x, float y);
void particles_set_form(emitter_t *emitter, char *form);
void particles_set_color(emitter_t *emitter, int red, int green, int blue);
/* lib/src/particles/render.c */
void draw_emitter_circle(sfRenderWindow *win, particle_node *temp,
    long int sec, emitter_t *emitter);
void draw_emitter_square(sfRenderWindow *win, particle_node *temp,
    long int sec, emitter_t *emitter);
void pos_particle(particle_node *temp, long int sec);
void size_particle(particle_node *temp, long int sec);

typedef struct emitter_struct emitter_t;
#endif
