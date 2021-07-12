/*
** EPITECH PROJECT, 2021
** inv utils
** File description:
** inv utils
*/

#include "rpg.h"

player_t *put_rect(player_t *player, int nb)
{
    player->weapon = player->inv->items[nb];
    player->inv->hotrect->pos.x = (float) player->inv->slot_pos[nb][0] + 2;
    player->inv->hotrect->pos.y = (float) player->inv->slot_pos[nb][1] - 7;
    return player;
}