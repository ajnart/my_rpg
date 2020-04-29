/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display.c
*/

#include "emitter.h"

void manage_first_clock(emitter_t *emitter)
{
    if (!emitter->ref) {
        emitter->ref = sfClock_create();
        return;
    }
    else if (sfClock_getElapsedTime(emitter->ref).microseconds > 1000000 &&
            !emitter->particles_first)
        sfClock_restart(emitter->ref);
}

int is_delay(emitter_t *emitter)
{
    long ref = 0;

    if (!emitter->ref) {
        emitter->ref = sfClock_create();
        return (1);
    }
    ref = sfClock_getElapsedTime(emitter->ref).microseconds;
    if (ref > 1000000 / emitter->nb) {
        sfClock_restart(emitter->ref);
        return (ref / (1000000 / emitter->nb));
    }
    return (0);
}

void draw_emitter(sfRenderWindow *win, emitter_t *emitter)
{
    particle_node *temp = emitter->particles_first;
    long int sec = 0;

    if (!temp)
        return;
    for (; temp; temp = temp->next) {
        sec = sfClock_getElapsedTime(temp->time_alive).microseconds;
        if (sec > temp->life_time) {
            emitter_delete(temp, emitter);
            continue;
        }
        pos_particle(temp, sec);
        size_particle(temp, sec);
        draw_emitter_circle(win, temp, sec, emitter);
        draw_emitter_square(win, temp, sec, emitter);
    }
}

void display_particles(sfRenderWindow *win, emitter_t *emitter,
sfVector2i mouse)
{
    int nb = 0;

    manage_first_clock(emitter);
    if ((nb = is_delay(emitter)))
        add_node(emitter, win, mouse, nb);
    draw_emitter(win, emitter);
    return;
}