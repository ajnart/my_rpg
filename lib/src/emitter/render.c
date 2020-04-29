/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** render.c
*/

#include "emitter.h"

void draw_emitter_circle(sfRenderWindow *win, particle_node *temp,
long int sec, emitter_t *emitter)
{
    if (temp->form)
        return;
    sfVector2f center = {temp->size  / 2, temp->size  / 2};
    set_particle_color(emitter, temp, sec);
    sfCircleShape_setOrigin(emitter->circle, center);
    sfCircleShape_setPosition(emitter->circle, *temp->pos);
    sfCircleShape_setFillColor(emitter->circle, temp->color);
    sfCircleShape_setRadius(emitter->circle, temp->size);
    sfRenderWindow_drawCircleShape(win, emitter->circle, NULL);
}

void draw_emitter_square(sfRenderWindow *win, particle_node *temp,
long int sec, emitter_t *emitter)
{
    sfVector2f size = {temp->size, temp->size};
    if (!temp->form)
        return;
    sfVector2f center = {temp->size / 2, temp->size / 2};
    set_particle_color(emitter, temp, sec);
    sfRectangleShape_setOrigin(emitter->square, center);
    sfRectangleShape_setPosition(emitter->square, *temp->pos);
    sfRectangleShape_setFillColor(emitter->square, temp->color);
    sfRectangleShape_setSize(emitter->square, size);
    sfRenderWindow_drawRectangleShape(win, emitter->square, NULL);
}

void pos_particle(particle_node *temp, long int sec)
{
    temp->pos->x = temp->initial_pos->x + (temp->range * temp->dir->x) *
    ((float)sec / (float)temp->life_time);
    temp->pos->y = temp->initial_pos->y + (temp->range * temp->dir->y) *
    ((float)sec / (float)temp->life_time);
}

void size_particle(particle_node *temp, long int sec)
{
    temp->size = temp->initial_size * (1 - (float)sec /
    (float)temp->life_time);
}