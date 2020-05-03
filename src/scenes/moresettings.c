/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** moresettings.c
*/

#include "main.h"
#include "rpg.h"
#include "buttons.h"
#include "lib.h"

void buy_perks(sfRenderWindow *win, game_t *game, event_st *state)
{
    if (my_strcmp(state->data, "buy_s") && game->knight.stats.gold >= 50) {
        game->knight.stats.gold -= 50;
        game->knight.stats.strength += 10;
    }
    if (my_strcmp(state->data, "buy_r") && game->knight.stats.gold >= 50) {
        game->knight.stats.gold -= 50;
        game->knight.stats.mobility += 1;
    }
    if (my_strcmp(state->data, "buy_l") && game->knight.stats.gold >= 50) {
        game->knight.stats.gold -= 50;
        game->knight.stats.luck += 1;
    }
    if (my_strcmp(state->data, "buy_m") && game->knight.stats.gold >= 50) {
        game->knight.stats.gold -= 50;
        game->knight.stats.maxhealth += 10;
    }
}

void add_buttons_paused(int WW, int WH)
{
    sfTexture *tx = find_asset_byname("button.png")->asset_store.texture;

    add_button(&g_buttons, "backg", mkf_rect((sfFloatRect)
        {WW*0.85, WH*0.9, WW*0.15, WH*0.1}, tx, sfGreen), "Back to game");
    add_button(&g_buttons, "exitg", mkf_rect((sfFloatRect)
        {WW*0.85, WH*0.8, WW*0.15, WH*0.1}, tx, sfRed), "Save and quit");
    add_button(&g_buttons, "buy_s", mkf_rect((sfFloatRect)
        {WW*0.15, WH*0.25, WW*0.15,
            WH*0.1}, 0, sfRed), "Strenght upgrade(50g)");
    add_button(&g_buttons, "buy_r", mkf_rect((sfFloatRect)
        {WW*0.30, WH*0.25, WW*0.15, WH*0.1}, 0, sfRed), "Speed upgrade(50g)");
    add_button(&g_buttons, "buy_l", mkf_rect((sfFloatRect)
        {WW*0.45, WH*0.25, WW*0.15, WH*0.1}, 0, sfRed), "Luck upgrade (50g)");
    add_button(&g_buttons, "buy_m", mkf_rect((sfFloatRect)
        {WW*0.60, WH*0.25, WW*0.15, WH*0.1}, 0, sfRed), "Maxhp upgrade (50g)");
}