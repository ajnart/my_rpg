/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** mob.c
*/

#include "entity.h"
#include "graphlib.h"
#include "lib.h"

void render_health_bar(sfRenderWindow *win, mob_s *mob)
{
    if (mob->life <= 0)
        return;
    int WW = settings->WW;
    int WH = settings->WH;
    sfText *text = sfText_create();
    rect_text info;
    sfRectangleShape *render;
    render = mkf_rect((sfFloatRect){mob->position.x- (mob->life *0.5),
        mob->position.y - WH*0.1, mob->life * WW*0.07 / 100, WH* 0.015},
        find_asset_byname("button.png")->asset_store.texture, sfRed);
    info = (rect_text){render, text, "", sfWhite, 8};
    add_rect_text(win, &info);
    sfText_destroy(text);
    sfRectangleShape_destroy(render);
}

void get_damage(knight_s *knight, mob_s *mob)
{
    if (mob->rect_a.left == 640) {
        knight->stats.health -= mob->damage;
    }
}

void case_mob(sfRenderWindow *win, mob_s *mob, int k_pos, game_t *game)
{
    switch (mob->state) {
    case 1:
        draw_mob_idle(win, mob);
        break;
    case 2:
        draw_mob_walking(win, mob, k_pos);
        break;
    case 3:
        draw_mob_attacking(win, mob, &(game->knight));
        break;
    case 4:
        draw_mob_dead(win, mob, game);
    default:
        break;
    }
}

void draw_mob(sfRenderWindow *win, mob_s *mob, int k_pos, game_t *game)
{
    while (mob) {
        case_mob(win, mob, k_pos, game);
        mob_aggro(game->mob, k_pos);
        sfSprite_setPosition(mob->sprite, mob->position);
        sfRenderWindow_drawSprite(win, mob->sprite, NULL);
        render_health_bar(win, mob);
        if (mob->life <= 0)
            mob->state = 4;
        if (mob->alive == 0)
            mob = delete_mob(win, game, mob);
        else
            mob = mob->next;
    }
}