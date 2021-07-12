/*
** EPITECH PROJECT, 2021
** weapon type
** File description:
** weapon type
*/

#include "rpg.h"

weapon_t *create_glock(weapon_t *item, inventory_t *inv, int i)
{
    item->dmg = (rand() % 16) + 12;
    item->ms = (rand() % 201) + 900;
    item->object = create_object("image/glock.png",
    inv->slot_pos[i][1], inv->slot_pos[i][0]);
    item->clock = sfClock_create();
    inv->items[i]->canshoot = 1;
    inv->items[i]->index = i;
    return item;
}

weapon_t *create_rifle(weapon_t *item, inventory_t *inv, int i)
{
    item->dmg = (rand() % 11) + 10;
    item->ms = (rand() % 301) + 400;
    item->object = create_object("image/rifle.png",
    inv->slot_pos[i][1], inv->slot_pos[i][0]);
    item->clock = sfClock_create();
    inv->items[i]->canshoot = 1;
    inv->items[i]->index = i;
    return item;
}

weapon_t *create_snipe(weapon_t *item, inventory_t *inv, int i)
{
    item->dmg = (rand() % 21) + 20;
    item->ms = (rand() % 301) + 1300;
    item->object = create_object("image/snipe.png",
    inv->slot_pos[i][1], inv->slot_pos[i][0]);
    item->clock = sfClock_create();
    inv->items[i]->canshoot = 1;
    inv->items[i]->index = i;
    return item;
}