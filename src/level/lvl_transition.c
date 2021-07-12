/*
** EPITECH PROJECT, 2021
** lvl_transition
** File description:
** lvl_transition
*/

#include "rpg.h"

static window_t *start_transition(window_t *win, level_t *lvl, pbl_t *game)
{
    if (win->l_state == 1)
        win->transcolor += 5;
    if (win->transcolor == 255 && win->l_state == 1) {
        ++lvl->lvl;
        if (lvl->maps[lvl->lvl] == NULL) {
            launch_transition(win, 4);
            transition(win);
            return win;
        }
        win->map_pos = lvl->spawns[lvl->lvl];
        lvl->ennemy[lvl->lvl] = create_ennemies(lvl, win->l_mod,
            (int) lvl->spawns[lvl->lvl].x, (int) lvl->spawns[lvl->lvl].y);
        win->l_state = 2;
    } else if (win->l_state == 2)
        win->transcolor -= 10;
    if (win->transcolor <= 0 && win->l_state == 2) {
        win->l_state = 0;
        win->transcolor = 0;
    }
    return win;
}

void launch_lvl_transition(window_t *win, level_t *lvl, player_t *player)
{
    sfVector2f pos = win->map_pos;

    if (pos.x + 30 - 943 < lvl->warps[lvl->lvl].x + 96
        && pos.x + 70 - 943 > lvl->warps[lvl->lvl].x
        && pos.y - 430 < lvl->warps[lvl->lvl].y + 96
        && pos.y - 450 > lvl->warps[lvl->lvl].y) {
        sfSound_play(win->sound->list[11]);
        if (lvl->lvl < 6)
            win->l_mod = 15 * (lvl->lvl + 1);
        else
            win->l_mod = (15 * (lvl->lvl + 1)) / 2;
        win->l_state = 1;
    }
}

void lvl_transition(window_t *win, level_t *lvl, player_t *player, pbl_t *game)
{
    launch_lvl_transition(win, lvl, player);
    win = start_transition(win, lvl, game);
    sfSprite_setColor(win->trans->sprite,
    sfColor_fromRGBA(0, 0, 0, win->transcolor));
    draw(win->window, win->trans->sprite);
}