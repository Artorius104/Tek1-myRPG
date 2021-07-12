/*
** EPITECH PROJECT, 2021
** mode
** File description:
** mode
*/

#include "rpg.h"

static sfSprite *anim_tp(sfSprite **tp, sfClock *clock, sfVector2f pos, int rs)
{
    static int i = 0;
    sfTime time = sfClock_getElapsedTime(clock);

    pos.x -= 80;
    pos.y -= 14;
    if (rs != 1)
        i = 0;
    else if (time.microseconds / 100000.0 > 1) {
        if (tp[i + 1] == NULL)
            i = 0;
        ++i;
        sfClock_restart(clock);
    }
    sfSprite_setPosition(tp[i], pos);
    return tp[i];
}

static void draw_sprite(window_t *win, pbl_t *game, char c, sfVector2f pos)
{
    if (c >= 'A' && c <= 'P') {
        sfSprite_setPosition(game->ground[c - 'A'], pos);
        draw(win->window, game->ground[c - 'A']);
    } else if (c == '3' || c == '0') {
        sfSprite_setPosition(game->ground['F' - 'A'], pos);
        draw(win->window, game->ground['F' - 'A']);
    }
}

void draw_ground(window_t *win, pbl_t *game, level_t *lvl)
{
    sfVector2f pos = {win->map_pos.x, win->map_pos.y};
    sfVector2f tp_pos;
    char **map = lvl->maps[lvl->lvl];
    int nb = 0;

    win->back->pos.x = (win->map_pos.x / 2) - 700;
    win->back->pos.y = (win->map_pos.y / 2) - 300;
    sfSprite_setPosition(win->back->sprite, win->back->pos);
    draw(win->window, win->back->sprite);
    for (int x = 0; map[x] != NULL; pos.x = win->map_pos.x, pos.y += 96.0, ++x)
        for (int y = 0; map[x][y] != '\0'; pos.x += 96.0, ++y) {
            if (map[x][y] == '0')
                tp_pos = pos;
            if (map[x][y] == '2') {
                sfSprite_setPosition(game->ground['F' - 'A'], pos);
                draw(win->window, game->ground['F' - 'A']);
            }
            draw_sprite(win, game, map[x][y], pos);
        }
    draw(win->window, anim_tp(game->tp, game->tp_clock, tp_pos, win->l_state));
}