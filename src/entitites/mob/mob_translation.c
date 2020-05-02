/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** mob_translation.c
*/

#include "entity.h"

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