/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** asset_utils.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/asset_loader.h"
#include "../../include/lib.h"

char *get_asset_fullpath(char *filename)
{
    char *result = my_strdup("assets/");

    str_append(&result, "/");
    str_append(&result, filename);
    return (result);
}
