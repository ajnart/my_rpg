/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "emitter.h"

int my_cstrcmp(char const *s1, char const *s2)
{
    for (int i = 0;; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return (s1[i] - s2[i]);
    }
    return (0);
}

void set_particle_color(emitter_t *emitter, particle_node * temp,
long int sec)
{
    temp->color.a = emitter->color.a * (1 - (float)sec /
    (float)temp->life_time);
}

sfVector2f *init_pos_particles(float x, float y)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f));

    if (!pos)
        return (NULL);
    pos->x = x;
    pos->y = y;
    return (pos);
}

void particles_set_form(emitter_t *emitter, char *form)
{
    if (!form)
        return;
    if (!my_cstrcmp(form, "random")) {
        emitter->form[0] = 1;
        emitter->form[1] = 1;
        return;
    } else if (!my_cstrcmp(form, "square")) {
        emitter->form[0] = 0;
        emitter->form[1] = 1;
        return;
    }
    if (!my_cstrcmp(form, "circle")) {
        emitter->form[0] = 1;
        emitter->form[1] = 0;
        return;
    }
    write(2, "Set_form: unknown form\n", 24);
}

void particles_set_color(emitter_t *emitter, int red, int green, int blue)
{
    emitter->color.r = red;
    emitter->color.g = green;
    emitter->color.b = blue;
    if (red == -1)
        emitter->random_color.r = 1;
    if (green == -1)
        emitter->random_color.g = 1;
    if (blue == -1)
        emitter->random_color.b = 1;
}