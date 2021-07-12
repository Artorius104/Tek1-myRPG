/*
** EPITECH PROJECT, 2021
** transi
** File description:
** transi
*/

#include "rpg.h"

void transition(window_t *win)
{
    if (win->t_state == 1)
        win->transcolor += 5;
    if (win->transcolor >= 255) {
        win->mod = win->t_mod;
        win->t_state = 2;
    }
    if (win->t_state == 2)
        win->transcolor -= 10;
    if (win->transcolor <= 0) {
        win->transcolor = 0;
        win->t_state = 0;
    }
    sfSprite_setColor(win->trans->sprite,
    sfColor_fromRGBA(0, 0, 0, win->transcolor));
    draw(win->window, win->trans->sprite);
}

void launch_transition(window_t *win, int mod)
{
    win->t_mod = mod;
    win->t_state = 1;
}