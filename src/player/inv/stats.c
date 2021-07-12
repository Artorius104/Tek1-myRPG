/*
** EPITECH PROJECT, 2021
** weapon_stats
** File description:
** weapon_stats
*/

#include "rpg.h"

void put_weapon_info(weapon_t *item, inventory_t *inv, window_t *win, int x)
{
    inv->stat_txt->pos.x = 1470 + x;
    inv->stat_txt->pos.y = 390;
    sfText_setString(inv->stat_txt->text, my_itoa(item->dmg));
    sfText_setPosition(inv->stat_txt->text, inv->stat_txt->pos);
    sfRenderWindow_drawText(win->window, inv->stat_txt->text, NULL);
    inv->stat_txt->pos.x = 1470 + x;
    inv->stat_txt->pos.y = 460;
    sfText_setString(inv->stat_txt->text, my_itoa(item->ms / 100));
    sfText_setPosition(inv->stat_txt->text, inv->stat_txt->pos);
    sfRenderWindow_drawText(win->window, inv->stat_txt->text, NULL);
}

void put_diff2(int nb, int y, inventory_t *inv, window_t *win)
{
    inv->stat_txt->pos.x = 1610;
    inv->stat_txt->pos.y = 390 + y;
    sfText_setString(inv->stat_txt->text, my_itoa(nb));
    sfText_setPosition(inv->stat_txt->text, inv->stat_txt->pos);
    sfRenderWindow_drawText(win->window, inv->stat_txt->text, NULL);
}

void put_diff(inventory_t *inv, window_t *win)
{
    int dmg = inv->stock->dmg - inv->items[inv->s_index]->dmg;
    int ms = (inv->stock->ms - inv->items[inv->s_index]->ms) / 100;

    if (dmg > 0)
        sfText_setColor(inv->stat_txt->text, sfColor_fromRGB(60, 179, 113));
    else if (dmg < 0)
        sfText_setColor(inv->stat_txt->text, sfColor_fromRGB(139, 0, 0));
    else
        sfText_setColor(inv->stat_txt->text, sfColor_fromRGBA(0, 0, 0, 0));
    put_diff2(dmg, 0, inv, win);
    if (ms > 0)
        sfText_setColor(inv->stat_txt->text, sfColor_fromRGB(139, 0, 0));
    else if (ms < 0)
        sfText_setColor(inv->stat_txt->text, sfColor_fromRGB(60, 179, 113));
    else
        sfText_setColor(inv->stat_txt->text, sfColor_fromRGBA(0, 0, 0, 0));
    put_diff2(ms, 70, inv, win);
}

void print_stats(inventory_t *inv, window_t *win)
{
    sfText_setColor(inv->stat_txt->text, sfColor_fromRGB(200, 200, 200));
    if (inv->items[inv->s_index] != NULL && inv->stock == NULL)
        put_weapon_info(inv->items[inv->s_index], inv, win, 0);
    if (inv->items[inv->s_index] == NULL && inv->stock != NULL)
        put_weapon_info(inv->stock, inv, win, 0);
    if (inv->items[inv->s_index] != NULL && inv->stock != NULL
        && inv->items[inv->s_index2] == NULL)
        put_weapon_info(inv->stock, inv, win, 0);
    if (inv->items[inv->s_index] != NULL && inv->stock != NULL
        && inv->items[inv->s_index2] != NULL) {
        put_weapon_info(inv->stock, inv, win, 0);
        put_weapon_info(inv->items[inv->s_index], inv, win, 70);
        put_diff(inv, win);
    }
}