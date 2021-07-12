/*
** EPITECH PROJECT, 2021
** chest_hb
** File description:
** chest_hb
*/

#include "rpg.h"

int open_chest(window_t *win, level_t *lvl, player_t *player, int i)
{
    if (player->object->pos.x <= lvl->chests[lvl->lvl][i]->pos.x + 157
        && player->object->pos.x + 100 >= lvl->chests[lvl->lvl][i]->pos.x + 50
        && player->object->pos.y <= lvl->chests[lvl->lvl][i]->pos.y + 100
        && player->object->pos.y + 134 >= lvl->chests[lvl->lvl][i]->pos.y
        && lvl->chests[lvl->lvl][i]->is_closed == 0) {
        draw(win->window, player->press_space->sprite);
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
            return 1;
        }
    return 0;
}