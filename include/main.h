/*
** EPITECH PROJECT, 2019
** WORLD
** File description:
** Sekaaaai de ichiban no himesamaaaaa
*/

#ifndef __MAIN_H
#define __MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#include "../src/assets/asset_loader.h"
#include "../src/settings/settings.h"

extern asset_store_t *g_assets;
extern settings_t *settings;

#define MALLOC(var, size)   \
malloc(size);               \
if (!var)                   \
    return NULL;

#endif //__MAIN_H
