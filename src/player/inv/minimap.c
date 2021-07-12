/*
** EPITECH PROJECT, 2021
** minimap
** File description:
** minimap
*/

#include "rpg.h"

inventory_t *change_mc(window_t *win, level_t *lvl, inventory_t *inv, int c)
{
    sfColor outcolor = sfColor_fromRGBA(100, 100, 100, 200);
    if (c == ' ')
        outcolor = sfColor_fromRGBA(100, 100, 100, 200);
    if (c == '3')
        outcolor = sfColor_fromRGBA(100, 10, 100, 200);
    if (c != ' ' && c != '3')
        outcolor = sfColor_fromRGBA(200, 200, 200, 200);
    sfRectangleShape_setOutlineColor(inv->mini_rect->rect, outcolor);
    sfRectangleShape_setFillColor(inv->mini_rect->rect, outcolor);
    return inv;
}

inventory_t *change_to_red(inventory_t *inv)
{
    sfColor outcolor = sfColor_fromRGBA(200, 30, 30, 200);
    sfRectangleShape_setOutlineColor(inv->mini_rect->rect, outcolor);
    sfRectangleShape_setFillColor(inv->mini_rect->rect, outcolor);
    return inv;
}

void draw_minimap(window_t *win, level_t *lvl, player_t *player)
{
    int x = (win->map_pos.x * -1 + 1010) / 96;
    int y = (win->map_pos.y * -1 + 560) / 96;

    for (int i = 0; lvl->maps[lvl->lvl][i] != NULL; ++i)
        for (int t = 0; lvl->maps[lvl->lvl][i][t] != '\0'; ++t) {
            player->inv->mini_rect->pos.x = t * 5 + 5;
            player->inv->mini_rect->pos.y = i * 5 + 5;
            sfRectangleShape_setPosition(player->inv->mini_rect->rect,
            player->inv->mini_rect->pos);
            player->inv = change_mc(win, lvl, player->inv,
            lvl->maps[lvl->lvl][i][t]);
            if (x == t && y == i)
                player->inv = change_to_red(player->inv);
            sfRenderWindow_drawRectangleShape(win->window,
            player->inv->mini_rect->rect, NULL);
        }
}