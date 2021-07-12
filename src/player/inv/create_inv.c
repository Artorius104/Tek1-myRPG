/*
** EPITECH PROJECT, 2021
** create_inv
** File description:
** create_inv
*/

#include "rpg.h"

rect_t *create_inv_rect(int a)
{
    rect_t *obj = malloc(sizeof(rect_t));

    obj->rect = sfRectangleShape_create();
    sfColor outcolor = sfColor_fromRGBA(8, 98, 175, a);
    sfColor incolor = sfColor_fromRGBA(8, 98, 175, a);
    obj->size.x = 74;
    obj->size.y = 74;
    sfRectangleShape_setSize(obj->rect, obj->size);
    sfRectangleShape_setOutlineColor(obj->rect, outcolor);
    sfRectangleShape_setFillColor(obj->rect, incolor);
    sfRectangleShape_setOutlineThickness(obj->rect, 1);
    return obj;
}

rect_t *create_minimap_rect(void)
{
    rect_t *obj = malloc(sizeof(rect_t));

    obj->rect = sfRectangleShape_create();
    sfColor outcolor = sfColor_fromRGBA(100, 100, 100, 200);
    obj->size.x = 5;
    obj->size.y = 5;
    sfRectangleShape_setSize(obj->rect, obj->size);
    sfRectangleShape_setOutlineColor(obj->rect, outcolor);
    sfRectangleShape_setFillColor(obj->rect, outcolor);
    return obj;
}

inventory_t *create_inventory2(inventory_t *inv, sfVector2f pos)
{
    inv->display = 0;
    inv->is_swapping = 0;
    inv->hotrect->pos.x = 1776.0;
    inv->hotrect->pos.y = 313.0;
    inv->s_index = 21;
    sfRectangleShape_setPosition(inv->hotrect->rect, inv->hotrect->pos);
    inv->stat_b = create_object("image/stats.png", 1300, 300);
    inv->trash = create_object("image/trash.png", 1779, 860);
    inv->stat_txt = create_text("yo", 0, 0, 45);
    inv->items[24] = malloc(sizeof(weapon_t));
    inv->mini_rect = create_minimap_rect();
    return inv;
}

inventory_t *create_inventory(inventory_t *inv, sfVector2f pos)
{
    inv = malloc(sizeof(inventory_t));
    inv->object = create_object("image/inv.png", 1300, 600);
    inv->hotbar = create_object("image/hotb.png", 1762, 300);
    sfColor grey = {155, 155, 155, 255};
    sfSprite_setColor(inv->object->sprite, grey);
    inv->items = malloc(sizeof(weapon_t *) * 25);
    inv->slot_pos = malloc(sizeof(int *) * 25);
    for (int i = 0; i < 25; i++) {
        inv->items[i] = malloc(sizeof(weapon_t));
        inv->slot_pos[i] = malloc(sizeof(int) * 2);
        inv->slot_pos[i][0] = 0;
        inv->slot_pos[i][1] = 0;
        inv->items[i] = NULL;
    }
    inv->items[21] = malloc(sizeof(weapon_t));
    inv->stock = NULL;
    inv->rect = create_inv_rect(100);
    inv->hotrect = create_inv_rect(50);
    inv = create_inventory2(inv, pos);
    return inv;
}