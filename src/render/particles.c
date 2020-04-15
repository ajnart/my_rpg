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

void print_message(char *str, sfRenderWindow *win, char *s_ft, sfVector2f info);

void draw_particles(sfRenderWindow *win, int number, button_store_t *button)
{
    // sfVector2f position = sfRectangleShape_getPosition(button->render);
    // color.r = abs(color.r - 60);
    // color.b = abs(color.b - 60);
    // sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->render);
    sfCircleShape *shape = sfCircleShape_create();
    for (int i = 0; i < number; i++) {
        sfCircleShape_setPosition(shape, (sfVector2f){rand()%settings->WW, rand()%settings->WH});
        sfCircleShape_setFillColor(shape, (sfColor){rand()%255,rand()%255,rand()%255, 255});
        sfCircleShape_setRadius(shape, (rand()%50) + 20);
        sfRenderWindow_drawCircleShape(win, shape, NULL);
        sfRenderWindow_display(win);
    }
    sfCircleShape_destroy(shape);
}
// Todo : Make it so that the effect is inside the buttons and color depends on the button's color.

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
