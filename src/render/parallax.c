/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parallax.c
*/

#include "lib.h"
#include "rpg.h"
#include "entity.h"

void append_parallax(t_para **para, char *pic, int speed)
{
    t_para *tmp = *para;
    t_para *element = malloc(sizeof(t_para));

    element->sprite = sfSprite_create();
    element->texture = find_asset_byname(pic)->asset_store.texture;
    element->rect = (sfIntRect){0, 0, settings->WW, settings->WH};
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

void direction_parallax(game_t *game, t_para *para,
int move_right, int move_left)
{
    if (move_right == 1 && check_collision_move(game, 1)) {
        if (para->rect.left >= settings->WW) {
            para->rect.left = 0;
            sfSprite_setTextureRect(para->sprite, para->rect);
        } else {
            para->rect.left += para->speed;
            sfSprite_setTextureRect(para->sprite, para->rect);
        } move_mob(game->mob, -1);
        move_npc(&(game->npc), -1);
        move_boss(&(game->boss), -1);
    } if (move_left == 1 && check_collision_move(game, -1)) {
        if (para->rect.left <= 0) {
            para->rect.left = 1280;
            sfSprite_setTextureRect(para->sprite, para->rect);
        } else {
            para->rect.left -= para->speed;
            sfSprite_setTextureRect(para->sprite, para->rect);
        } move_mob(game->mob, 1);
        move_npc(&(game->npc), 1);
        move_boss(&(game->boss), 1);
    }
}

void draw_parallax(sfRenderWindow *win, game_t *game, event_st *state,
sfVector2f pos)
{
    int move_right = state->data && my_strcmp(state->data, "right")
    && pos.x >= settings->WW / 6 * 5;
    int move_left = state->data && my_strcmp(state->data, "left")
    && pos.x <= settings->WW / 6;
    t_para *para = game->para;

    while (para) {
        direction_parallax(game, para, move_right, move_left);
        sfRenderWindow_drawSprite(win, para->sprite, NULL);
        para = para->next;
    }
}