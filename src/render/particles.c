/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particles.c
*/

#include <stdio.h>
#include <math.h>
#include "../events/buttons.h"
#include "main.h"

void draw_particles(sfRenderWindow *win, int number, button_store_t *button)
{
    // sfVector2f position = sfRectangleShape_getPosition(button->render);
    // color.r = abs(color.r - 60);
    // color.g = abs(color.g - 60);
    // color.b = abs(color.b - 60);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->render);
    for (int i = 0; i < number; i++) {
        sfCircleShape *shape = sfCircleShape_create();
        sfCircleShape_setPosition(shape, (sfVector2f){bounds.top + rand()%200, bounds.left - rand()%200});
        sfCircleShape_setFillColor(shape, sfBlue);
        sfCircleShape_setRadius(shape, 5);
        sfRenderWindow_drawCircleShape(win, shape, NULL);
        sfRenderWindow_display(win);
        sfCircleShape_destroy(shape);
    }
}


// void draw_particles(sfRenderWindow *win, sfVector2u position, int number)
// {
//     int i = 0;
//     sfUint8 unit = malloc(sizeof(sfUint8) * number);
//     sfTexture *texture = sfTexture_create(settings->WW, settings->WH);
//     static int **table;
//     if (!table) {
//         table = (int**)malloc(number * sizeof(int*));
//         for(i = 0; i < number; i++) {
//             table[i] = (int*)malloc(3 * sizeof(int));
//             table[i][2] = 120;
//             table[i][0] = position.x;
//             table[i][1] = position.y;
//         }
//     }
//     sfTexture_updateFromPixels(texture, , )
// }
