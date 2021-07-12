/*
** EPITECH PROJECT, 2021
** weapons
** File description:
** weapons
*/

#include "rpg.h"

inventory_t *generate_weapon(inventory_t *inv)
{
    int i = 0;

    for (; inv->items[i] != NULL; ++i);
    if (i < 21) {
        inv->items[i] = malloc(sizeof(weapon_t));
        inv->items[i]->type = rand() % 3;
        if (inv->items[i]->type == 0)
            inv->items[i] = create_glock(inv->items[i] , inv, i);
        else if (inv->items[i]->type == 2)
            inv->items[i] = create_rifle(inv->items[i] , inv, i);
        else
            inv->items[i] = create_snipe(inv->items[i] , inv, i);
    }
    return inv;
}

int find_slot(inventory_t *inv, window_t *win)
{
    for (int i = 0; i < 25; i++)
        if (win->mouse.x >= inv->slot_pos[i][0]
            && win->mouse.x <= inv->slot_pos[i][0] + 79
            && win->mouse.y  >= inv->slot_pos[i][1]
            && win->mouse.y  <= inv->slot_pos[i][1] + 78)
            return i;
    return -1;
}

inventory_t *drop(inventory_t *inv, window_t *win)
{
    int swap = 0;

    if (inv->is_swapping == 0 && inv->stock != NULL) {
        swap = find_slot(inv, win);
        if (swap == -1)
            inv->items[inv->index] = inv->stock;
        if (swap != -1 && inv->items[swap] != NULL && inv->stock != NULL) {
            inv->items[inv->prev_index] = inv->items[swap];
            inv->items[swap] = inv->stock;
        }
        if (swap != -1 && inv->items[swap] == NULL)
            inv->items[swap] = inv->stock;
        inv->stock = NULL;
    }
    inv->items[24] = NULL;
    return inv;
}

player_t *switch_weapons(inventory_t *inv, player_t *player, window_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1) == sfTrue && inv->items[21])
        player = put_rect(player, 21);
    if (sfKeyboard_isKeyPressed(sfKeyNum2) == sfTrue && inv->items[22])
        player = put_rect(player, 22);
    if (sfKeyboard_isKeyPressed(sfKeyNum3) == sfTrue && inv->items[23])
        player = put_rect(player, 23);
    sfRectangleShape_setPosition(player->inv->hotrect->rect,
    player->inv->hotrect->pos);
    if (player->inv->display != 1)
        sfRenderWindow_drawRectangleShape(win->window,
        player->inv->hotrect->rect, NULL);
    return player;
}

inventory_t *swap_items(inventory_t *inv, window_t *win)
{
    if (inv->is_swapping == 1 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && inv->items[inv->index] != NULL && inv->stock == NULL) {
        inv->stock = inv->items[inv->index];
        inv->items[inv->index] = NULL;
        inv->prev_index = inv->index;
    }
    if (inv->stock != NULL) {
        init_pos(inv->stock->object, win->mouse.x - 37, win->mouse.y - 35);
        draw(win->window, inv->stock->object->sprite);
    }
    inv = drop(inv, win);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
        inv->is_swapping = 0;
    return inv;
}