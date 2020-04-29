/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create.c
*/

#include "emitter.h"

int get_form(emitter_t *emitter);

sfColor copy_color_particle(sfColor color, color_t random)
{
    sfColor res;

    res.r = (random.r) ? rand() % 256 : color.r;
    res.g = (random.g) ? rand() % 256 : color.g;
    res.b = (random.b) ? rand() % 256 : color.b;
    res.a = color.a;
    return (res);
}

particle_node *init_emitter_node(emitter_t *emitter, sfVector2i *mouse)
{
    particle_node *res = malloc(sizeof(particle_node));
    if (!res)
        return (NULL);
    if (!(res->dir = init_pos_particles(create_dir(), create_dir())))
        return (NULL);
    res->form = get_form(emitter);
    if (!(res->initial_pos = init_pos_particles(mouse->x, mouse->y)))
        return (NULL);
    if (!(res->pos = init_pos_particles(mouse->x, mouse->y)))
        return (NULL);
    res->range = rand() % (emitter->range / 2) + emitter->range / 2;
    res->size = (rand() % emitter->max_size) *
                (float)((float)res->range / (float)emitter->range);
    res->initial_size = res->size;
    res->time_alive = sfClock_create();
    res->life_time = rand() % 200000 - 100000 + emitter->life_time;
    res->next = NULL;
    res->prev = NULL;
    res->color = copy_color_particle(emitter->color, emitter->random_color);
    return (res);
}

void add_node(emitter_t *emitter, sfRenderWindow *win,
sfVector2i mouse, int nb)
{
    particle_node *new = NULL;
    particle_node *temp = NULL;

    for (int i = 0; i < nb; i++) {
        new = init_emitter_node(emitter, &mouse);
        if (!new)
            return;
        if (!emitter->particles_first) {
            emitter->particles_first = new;
            return;
        }
        temp = emitter->particles_first;
        emitter->particles_first = new;
        emitter->particles_first->next = temp;
        temp->prev = emitter->particles_first;
    }
}

emitter_t *emitter_create(int number_per_sec)
{
    emitter_t *emitter = malloc(sizeof(emitter_t));

    if (!emitter)
        return (NULL);
    emitter->nb = number_per_sec;
    emitter->range = 100;
    emitter->is_attenuation = 1;
    emitter->form[0] = 1;
    emitter->form[1] = 0;
    emitter->circle = sfCircleShape_create();
    emitter->square = sfRectangleShape_create();
    emitter->particles_first = NULL;
    emitter->ref = NULL;
    emitter->life_time = 2000000;
    emitter->max_size = 20;
    emitter->color = sfWhite;
    emitter->random_color = (color_t){0, 0, 0};
    return (emitter);
}