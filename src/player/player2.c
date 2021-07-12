/*
** EPITECH PROJECT, 2021
** player2
** File description:
** player2
*/

#include "rpg.h"

void mv_win2(player_t *player, window_t *win, pbl_t * game)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) {
        if (collision_with_wall(game, win, 0, -player->speed) == 1)
            return;
        win->map_pos.y -= player->speed;
        win->mvmnt.y -= player->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        if (collision_with_wall(game, win, -player->speed, 0) == 1)
            return;
        win->map_pos.x -= player->speed;
        win->mvmnt.x -= player->speed;
    }
}