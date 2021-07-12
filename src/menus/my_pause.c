/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-julien.de-waele
** File description:
** my_pause.c
*/

#include "rpg.h"

void my_fps(window_t *win)
{
    if (win->mouse.x >= 659 && win->mouse.y >= 476
        && win->mouse.x <= 679 && win->mouse.y <= 496 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        win->fps = 30;
        sfRenderWindow_setFramerateLimit(win->window, win->fps);
    }
    if (win->mouse.x >= 948 && win->mouse.y >= 478
        && win->mouse.x <= 468 && win->mouse.y <= 497 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        win->fps = 60;
        sfRenderWindow_setFramerateLimit(win->window, win->fps);
    }
    if (win->mouse.x >= 1238 && win->mouse.y >= 477
        && win->mouse.x <= 1258 && win->mouse.y <= 497 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        win->fps = 90;
        sfRenderWindow_setFramerateLimit(win->window, win->fps);
    }
}

void my_pause(object_l *menu, window_t *win)
{
    draw(win->window, menu->menuparam->sprite);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        menu->mod = 0;
    my_fps(win);
}