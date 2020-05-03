/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** settings.c
*/

#include "rpg.h"
#include "main.h"
#include "buttons.h"
#include "lib.h"
#include "scenes.h"
#include "entity.h"

void messages_howtoplay(sfRenderWindow *win)
{
    int WW = settings->WW;
    int WH = settings->WH;
    print_message(my_sprintf("Hello %s !\nThe Bois De Boulogne is infested by \
the unholy unborns of past clients\nYour job is to get rid of them.\n\
the keys you will use to move are the folling:\n%s:UP\t%s:LEFT\t%s:DOWN\t%s:\
RIGHT\nPress space to swing your sword and slay enemies",
    settings->name, settings->keys->up, settings->keys->left,
    settings->keys->down, settings->keys->right), win, (float)1,
    (sfVector3f){WW*0.5, WH*0.1, 0});
}

void if_settings(event_st *state, void (**loop)(),
    sfRenderWindow *win, game_t *game)
{
    if (state->type == sfEvtMouseButtonPressed && state->data) {
        buy_perks(win, game, state);
        if (my_strcmp(state->data, "backm")) {
            *loop = &loop_menu;
            settings->paused = 0; }
        if (my_strcmp(state->data, "backg")) {
            settings->paused = 0;
            *loop = &loop_ingame; }
        if (my_strcmp(state->data, "vol_plus") && settings->volume <= 90)
            settings->volume += 10;
        if (my_strcmp(state->data, "vol_minus") && settings->volume >= 10)
            settings->volume -= 10;
        if (my_strcmp(state->data, "exitg"))
            save_and_quit(win, game);
        if (my_strcmp(state->data, "emitter")) {
            settings->emitter = settings->emitter == 0 ? 1 : 0;
            get_button(g_buttons, "emitter")->normal = get_button(g_buttons,
                "emitter")->normal.g == 255 ? sfRed : sfGreen;
        }
    }
}

void messages_settings(sfRenderWindow *win, int WW, int WH, game_t *game)
{
    if (settings->paused == 0) {
        messages_howtoplay(win);
    }
    else
    {
        sfText *text = sfText_create();
        rect_text info;
        sfRectangleShape *render;
        render = mkf_rect((sfFloatRect){0, 0, WW, WH* 0.25},
            find_asset_byname("button.png")->asset_store.texture, sfBlack);
        info = (rect_text){render, text, my_sprintf("Your stats:\
        strenght:%d, speed: %d, luck: %d, maxhp:%d\n\nYour gold coins:%d",
        game->knight.stats.strength, game->knight.stats.mobility,
        game->knight.stats.luck, game->knight.stats.maxhealth,
        game->knight.stats.gold), sfWhite, 3};
        add_rect_text(win, &info);
        sfText_destroy(text);
        sfRectangleShape_destroy(render);
    }
}

void loop_settings(sfRenderWindow *win, event_st *state,
    void (**loop)(), game_t *game)
{
    settings->paused ? 0: sfRenderWindow_clear(win, sfBlack);
    messages_settings(win, settings->WW, settings->WH, game);
    if_settings(state, loop, win, game);
    sfMusic_setVolume(find_asset_byname("music.wav")->asset_store.music,
        settings->volume);
    state->data = NULL;
}

void buttons_settings(sfRenderWindow *win, int WW, int WH)
{
    sfTexture *tx = find_asset_byname("button.png")->asset_store.texture;

    if (settings->paused)
        add_buttons_paused(WW, WH);
    add_button(&g_buttons, "backm", mkf_rect((sfFloatRect)
        {0, WH*0.9, WW*0.15, WH*0.1}, tx, sfRed), "Back to main menu");
    add_button(&g_buttons, "vol_minus", mkf_rect((sfFloatRect)
        {WW*0.075, WH*0.7, WW*0.075, WH*0.1}, tx, sfBlue), "vol -");
    add_button(&g_buttons, "vol_plus", mkf_rect((sfFloatRect)
        {0, WH*0.7, WW*0.075, WH*0.1}, tx, sfRed), "vol +");
    add_button(&g_buttons, "emitter", mkf_rect((sfFloatRect)
        {0, WH*0.8, WW*0.15, WH*0.1}, tx,
        settings->emitter == 0 ? sfRed : sfGreen), "particles on/off");
}