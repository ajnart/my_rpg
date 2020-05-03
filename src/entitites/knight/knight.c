/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** knight.c
*/

#include "entity.h"

void do_damage(mob_s *mob, knight_s *knight, int sign)
{
    int dist = 0;

    if (knight->render.rect_a.left == 384)  {
        while (mob) {
            dist = mob->position.x - knight->render.position.x;
            if (mob->state == 3 &&
            ((dist > 0 && sign > 0) || (dist < 0 && sign < 0))) {
                mob->life -= knight->stats.strength;
            }
            mob = mob->next;
        }
    }
}

void case_knight(sfRenderWindow *win, knight_s *knight, game_t *game)
{
    switch (knight->render.state) {
    case 1:
        draw_knight_idle(win, knight);
        break;
    case 2:
        draw_knight_walking(win, knight, 1);
        move_knight(game, 1);
        break;
    case 3:
        draw_knight_attacking(win, knight, game->mob);
        break;
    case 4:
        draw_knight_walking(win, knight, -1);
        move_knight(game, -1);
        break;
    case 5:
        draw_knight_translate(win, game, knight, 1);
        break;
    case 6:
        draw_knight_translate(win, game, knight, 2);
        break;
    default:
        break; }
}

void draw_knight(sfRenderWindow *win, knight_s *knight,
game_t *game)
{
    if (!knight->render.sprite)
        knight->render.sprite = sfSprite_create();
    case_knight(win, knight, game);
    sfSprite_setPosition(knight->render.sprite, knight->render.position);
    sfRenderWindow_drawSprite(win, knight->render.sprite, NULL);
}