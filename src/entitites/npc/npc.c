/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** npc.c
*/

#include "entity.h"

void move_npc(npc_t *npc, int way)
{
    if (way == 1)
        npc->position.x += 1;
    if (way == -1)
        npc->position.x -= 1;
}

void check_interact(sfRenderWindow *win, npc_t *npc, event_st *state)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f n_pos = npc->position;

    if (state->type != sfEvtMouseButtonPressed ||
    get_elapsed_time(npc->clicked) <= 0.5)
        return;
    if (m_pos.x >= n_pos.x - 40 && m_pos.x <= n_pos.x + 40 &&
    m_pos.y >= n_pos.y - 40 && m_pos.y <= n_pos.y + 40) {
        if (npc->text < 0)
            npc->text = npc->state;
        else
            npc->text = -1;
        if (npc->state == 0)
            npc->state = 1;
        else if (npc->state == 1)
            npc->state = 2;
        sfClock_restart(npc->clicked);
    }
}

void draw_quest_finished(sfRenderWindow *win, npc_t *npc)
{
    char *s = "You did it ! I always knew you were awesome!\n"
    "You have enough coins to buy the princess, congrats !";

    print_message(s, win, (float)0.8,
        (sfVector3f){npc->position.x,
        npc->position.y - (double)settings->WH / 4.8, 0});
}

void draw_quest_text(sfRenderWindow *win, npc_t *npc)
{
    int WW = settings->WW;
    int WH = settings->WH;
    char *s = "Hey ! My name is Rocco. I've been stuck here for 2 years, \n"
    "and I need your help ! Do you see those scary mobs ? \n"
    "Go defeat them and I will offer you a reward !"
    "\n\n(click again to continue)";
    char *s1 = "What are you doing ?!!\nGo defeat these mobs NOW!\n";

    if (npc->text < 0)
        return;
    if (npc->state == 1)
        print_message(s, win, (float)0.8,
        (sfVector3f){npc->position.x,
        npc->position.y - (double)settings->WH / 4.8, 0});
    else if (npc->state == 2)
        print_message(s1, win, (float)0.8,
        (sfVector3f){npc->position.x,
        npc->position.y - (double)settings->WH / 4.8, 0});
    else
        draw_quest_finished(win, npc);
}

void draw_npc(sfRenderWindow *win, npc_t *npc, event_st *state, game_t *game)
{
    draw_npc_idle(win, npc);
    check_interact(win, npc, state);
    sfSprite_setPosition(npc->sprite, npc->position);
    draw_quest_text(win, npc);
    sfRenderWindow_drawSprite(win, npc->sprite, NULL);
}