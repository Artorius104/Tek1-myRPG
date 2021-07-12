/*
** EPITECH PROJECT, 2021
** collisions with walls
** File description:
** collisions with walls
*/

#include "rpg.h"

int collision_with_wall(pbl_t *game, window_t *win, int dirx, int diry)
{
    player_t *player = game->player;
    int multx = dirx / player->speed == 0 ? 0 : dirx / player->speed;
    int multy = diry / player->speed == 0 ? 0 : diry / player->speed;
    int up = dirx == 0 && diry > 0 ? 40 : 0;
    int right = dirx < 0 && diry == 0 ? 15 : 0;
    int x = (-win->map_pos.x + player->object->pos.x + dirx +
        67.25 + 50 * -multx - 12 - right) / 96;
    int y = (-win->map_pos.y + player->object->pos.y + diry +
        73 + 50 * -multy + 12 + up) / 96;
    char obs = game->lvl->maps[game->lvl->lvl][y][x];

    if (obs != ' ' && obs != '2')
        return 0;
    return 1;
}