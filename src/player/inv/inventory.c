/*
** EPITECH PROJECT, 2021
** inventory
** File description:
** inventory
*/

#include "rpg.h"

player_t *update_slots_pos(player_t *player)
{
    sfVector2f pos = {1305, 612};
    for (int i = 0, t = 0, k = 0; i < 21; i++, t++) {
        if (t == 7 || t == 14) {
            t = 0;
            k++;
        }
        player->inv->slot_pos[i][0] = pos.x + t * 79.5;
        player->inv->slot_pos[i][1] = pos.y + k * 79.5;
    }
    player->inv->slot_pos[21][0] = 1774;
    player->inv->slot_pos[21][1] = 320;
    player->inv->slot_pos[22][0] = 1774;
    player->inv->slot_pos[22][1] = 400;
    player->inv->slot_pos[23][0] = 1774;
    player->inv->slot_pos[23][1] = 480;
    player->inv->slot_pos[24][0] = 1784;
    player->inv->slot_pos[24][1] = 873;
    return player;
}

int check_mouse_on_slot(player_t *player, window_t *win, int i)
{
    if (win->mouse.x >= player->inv->slot_pos[i][0]
        && win->mouse.x <= player->inv->slot_pos[i][0] + 79
        && win->mouse.y  >= player->inv->slot_pos[i][1]
        && win->mouse.y  <= player->inv->slot_pos[i][1] + 78)
        return 1;
    return 0;
}

player_t *reset_inv(player_t *player, window_t *win)
{
    player = update_slots_pos(player);
    player = switch_weapons(player->inv, player, win);
    for (int i = 0; i < 25; i++)
        if (check_mouse_on_slot(player, win, i) == 1) {
            if (player->inv->items[i] != NULL
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
                player->inv->is_swapping = 1;
                player->inv->index = i;
            }
            if (player->inv->items[i] != NULL)
                player->inv->s_index = i;
            player->inv->s_index2 = i;
            player->inv->rect->pos.x = (float) player->inv->slot_pos[i][0] + 2;
            player->inv->rect->pos.y = (float) player->inv->slot_pos[i][1] - 7;
        }
    sfRectangleShape_setPosition(player->inv->rect->rect,
    player->inv->rect->pos);
    return player;
}

void draw_inv(player_t *player, window_t *win)
{
    draw(win->window, player->inv->object->sprite);
    draw(win->window, player->inv->stat_b->sprite);
    draw(win->window, player->inv->trash->sprite);
    print_stats(player->inv, win);
    draw_inv_weapons(player->inv, win);
    sfRenderWindow_drawRectangleShape(win->window,
    player->inv->rect->rect, NULL);
    display_pstart(win, player);
}

void inventory_display(player_t *player, window_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue
        && player->inv->display == 0 && win->quest->mod == 3) {
        player->inv->display = 1;
        player->inv->rect->pos.x = (float) player->inv->slot_pos[0][0] + 2;
        player->inv->rect->pos.y = (float) player->inv->slot_pos[0][1] - 7;
        sfRectangleShape_setPosition(player->inv->rect->rect,
    player->inv->rect->pos);
        sfSound_play(win->sound->list[5]);
    }
    draw_hot_weapons(player->inv, win);
    if (player->inv->display == 1) {
        draw_inv(player, win);
        player->inv = swap_items(player->inv, win);
    }
    player = reset_inv(player, win);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue
        && player->inv->display == 1)
        player->inv->display = 0;
    if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue)
        player->inv = generate_weapon(player->inv);
}