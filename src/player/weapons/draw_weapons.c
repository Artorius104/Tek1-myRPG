/*
** EPITECH PROJECT, 2021
** draw_weapons
** File description:
** draw_weapons
*/

#include "rpg.h"

void draw_inv_weapons(inventory_t *inv, window_t *win)
{
    for (int i = 0; i < 22; ++i)
        if (inv->items[i] != NULL) {
            inv->items[i]->object = init_pos(inv->items[i]->object,
            inv->slot_pos[i][0], inv->slot_pos[i][1]);
            draw(win->window, inv->items[i]->object->sprite);
        }
}

void draw_hot_weapons(inventory_t *inv, window_t *win)
{
    draw(win->window, inv->hotbar->sprite);
    for (int i = 21; i < 24; ++i)
        if (inv->items[i] != NULL) {
            inv->items[i]->object = init_pos(
            inv->items[i]->object, inv->slot_pos[i][0], inv->slot_pos[i][1]);
            draw(win->window, inv->items[i]->object->sprite);
        }
}
