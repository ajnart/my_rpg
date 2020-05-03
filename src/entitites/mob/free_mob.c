/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** free_mob.c
*/

#include "entity.h"
#include "lib.h"

void free_mob(mob_s *mob)
{
    sfSprite_destroy(mob->sprite);
    sfClock_destroy(mob->clock);
}

int check_first(game_t *game, mob_s *mob)
{
    if (game->mob->position.x == mob->position.x &&
    game->mob->life == mob->life) {
        free_mob(game->mob);
        free(game->mob);
        game->mob = game->mob->next;
        return (1);
    }
    return (0);
}

mob_s *check_in(game_t *game, mob_s *mob)
{
    mob_s *tmp = game->mob;
    mob_s *save = NULL;

    while (tmp->next) {
        if (tmp->next->position.x == mob->position.x &&
        tmp->next->life == mob->life) {
            save = tmp->next;
            tmp->next = tmp->next->next;
            free_mob(save);
            free(save);
            return (tmp->next);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

mob_s *delete_mob(sfRenderWindow *win, game_t *game, mob_s *mob)
{
    mob_s *result = NULL;
    int gold = rand() % (20 + rand() % (game->knight.stats.luck * 4));

    send_notifs(win, "You have found", my_sprintf("%d gold!", gold), 70);
    game->knight.stats.gold += gold;
    if (game->mob->next == NULL) {
        free_mob(game->mob);
        free(game->mob);
        game->mob = NULL;
        return (NULL);
    }
    if (check_first(game, mob))
        return (game->mob);
    result = check_in(game, mob);
    return (result);
}