/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** cleanup.c
*/

#include "emitter.h"

void emitter_free(particle_node *temp)
{
    if (temp->dir)
        free(temp->dir);
    if (temp->initial_pos)
        free(temp->initial_pos);
    if (temp->pos)
        free(temp->pos);
    if (temp->time_alive)
        sfClock_destroy(temp->time_alive);
    free(temp);
}

void emitter_delete(particle_node *temp, emitter_t *emitter)
{
    particle_node *prev = temp->prev;

    if (!prev) {
        emitter->particles_first = temp->next;
        if (temp->next)
            temp->next->prev = NULL;
        emitter_free(temp);
        return;
    }
    prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    emitter_free(temp);
}

void emitter_cleanup(emitter_t *emitter)
{
    particle_node *temp = emitter->particles_first;
    particle_node *next = NULL;

    while (temp) {
        next = temp->next;
        emitter_delete(temp, emitter);
        temp = next;
    }
    if (emitter->circle)
        sfCircleShape_destroy(emitter->circle);
    if (emitter->ref)
        sfClock_destroy(emitter->ref);
    if (emitter->square)
        sfRectangleShape_destroy(emitter->square);
    free(emitter);
}

void emitter_interrup(emitter_t *emitter)
{
    if (emitter->ref)
        sfClock_destroy(emitter->ref);
    emitter->ref = NULL;
}

int get_form(emitter_t *emitter)
{
    if (emitter->form[0] && emitter->form[1])
        return (rand() % 2);
    else if (emitter->form[1])
        return (1);
    return (0);
}