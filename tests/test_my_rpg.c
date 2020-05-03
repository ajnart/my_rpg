/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** test_my_rpg.c
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <criterion/redirect.h>
#include "main.h"

int my_rpg(int ac, char **av);

const char *av[1] = { "./my_rpg", };

Test(world, world)
{
    cr_assert_eq(my_rpg(1, (char **)av[1]), NULL);
}