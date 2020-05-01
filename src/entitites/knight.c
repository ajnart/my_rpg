/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** knight.c
*/

#include "knight.h"

void draw_knight_idle(sfRenderWindow *win, knight_s *knight)
{
    if (knight->render.rect.left != 960)
        knight->render.rect.left += 64;
    else
        knight->render.rect.left = 0;
    sfSprite_setTexture(knight->render.sprite,
        find_asset_byname("Idle.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(knight->render.sprite, knight->render.rect);
}

void draw_knight_walking(sfRenderWindow *win, knight_s *knight)
{
    if (knight->render.rect.left != 768)
        knight->render.rect.left += 64;
    else
        knight->render.rect.left = 0;
    sfSprite_setTexture(knight->render.sprite,
        find_asset_byname("Run.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(knight->render.sprite, knight->render.rect);
}

void draw_knight_attacking(sfRenderWindow *win, knight_s *knight)
{
    if (knight->render.rect.left != 3200)
        knight->render.rect.left += 64;
    else
        knight->render.rect.left = 1728;
    sfSprite_setTexture(knight->render.sprite,
        find_asset_byname("Attack.png")->asset_store.texture, sfTrue);
    sfSprite_setTextureRect(knight->render.sprite, knight->render.rect);
}

void draw_knight(sfRenderWindow *win, knight_s *knight)
{
    if (!knight->render.sprite)
        knight->render.sprite = sfSprite_create();
    switch (knight->render.state)
    {
    case 1:
        draw_knight_idle(win, knight);
        break;
    case 2:
        draw_knight_walking(win, knight);
        break;
    case 3:
        draw_knight_attacking(win, knight);
        break;
    default:
        break;
    }
    sfSprite_setPosition(knight->render.sprite, knight->render.position);
    sfRenderWindow_drawSprite(win, knight->render.sprite, NULL);
}