/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parallax.c
*/

#include "rpg.h"
#include "parallax.h"

void append_parallax(t_para **para, char *pic, int speed)
{
    t_para *tmp = *para;
    t_para *element = malloc(sizeof(t_para));

    element->sprite = sfSprite_create();
    element->texture = find_asset_byname(pic)->asset_store.texture;
    element->rect = (sfIntRect){0, 0, 1280, 720};
    element->speed = speed;
    element->next = NULL;
    sfSprite_setTexture(element->sprite, element->texture, sfFalse);
    sfSprite_setTextureRect(element->sprite, element->rect);
    if (tmp == NULL)
        *para = element;
    else {
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = element;
    }
}

t_para *set_parallax(void)
{
    t_para *para = NULL;

    append_parallax(&para, "Foreground.png", 1);
    append_parallax(&para, "Back2.png", 2);
    append_parallax(&para, "Back1.png", 5);
    return (para);
}

void draw_parallax(sfRenderWindow *win, t_para *para)
{
    while (para) {
        if (para->rect.left == 1280) {
            para->rect.left = 0;
            sfSprite_setTextureRect(para->sprite, para->rect);
        } else {
            para->rect.left += para->speed;
            sfSprite_setTextureRect(para->sprite, para->rect);
        }
        sfRenderWindow_drawSprite(win, para->sprite, NULL);
        para = para->next;
    }
}