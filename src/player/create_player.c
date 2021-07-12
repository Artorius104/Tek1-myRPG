/*
** EPITECH PROJECT, 2021
** create_player
** File description:
** create_player
*/

#include "rpg.h"

player_t *create_player2(player_t *player)
{
    player->orb = malloc(sizeof(object_t) * 5);
    for (int i = 0; i < 5; ++i)
        player->orb[i] = NULL;
    player->press_space = create_object("image/press_space.png", 0, 0);
    player->pstat_page = create_object("image/pstat_page.png", 200, 300);
    player->stat_txt = create_text2("yo", 0, 0, 70);
    return player;
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->object = malloc(sizeof(object_t));
    player->shoot = malloc(sizeof(shoot_t *) * 10);
    for (int i = 0; i < 10; i++)
        player->shoot[i] = NULL;
    player->shootdir = 2;
    player->weapon = malloc(sizeof(weapon_t));
    player->stats = init_pstats();
    player->object = create_object("./image/player.png", 940, 420);
    player->object = init_rect(player->object, 100, 134, 268);
    player->object->clock = sfClock_create();
    player->direction = 4;
    player->lim = 300;
    player->inv = create_inventory(player->inv, player->object->pos);
    player->weapon = create_glock(player->inv->items[21],
    player->inv, 21);
    player->speed = 6;
    player = create_player2(player);
    return player;
}