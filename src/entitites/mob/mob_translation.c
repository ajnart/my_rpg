/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** mob_translation.c
*/

#include "entity.h"

void mob_aggro(mob_s *mob, int k_pos)
{
    int d = 0;
    int off = settings->WW / 20;
    int nb = 0;

    while (mob) {
        d = mob->position.x - k_pos;
        if ((mob->state == 1 && get_abs(d) <= 400) ||
        (mob->state == 3 && get_abs(d) > off + 4))
            mob->state = 2;
        if (mob->state == 2 && get_abs(d) >= 400)
            mob->state = 1;
        if (mob->state == 2 && d > 0 && get_abs(d) > off)
            mob->position.x -= mob->speed;
        else if (mob->state == 2 && get_abs(d) > off)
            mob->position.x += mob->speed;
        if (mob->state == 2 && get_abs(d) <= off)
            mob->state = 3;
        mob = mob->next;
        nb++;
    }
}

void move_mob(mob_s *mob, int way)
{
    while (mob) {
        if (way == 1)
            mob->position.x += 1;
        if (way == -1)
            mob->position.x -= 1;
        mob = mob->next;
    }
}