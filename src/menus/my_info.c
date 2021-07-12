/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-julien.de-waele
** File description:
** my_info.c
*/

#include "rpg.h"

void my_info(object_l *menu, window_t *win)
{
    static int i = 0;

    if (i == 0)
        draw(win->window, menu->info_one->sprite);
    if (win->mouse.x >= 1218 && win->mouse.y >= 800
        && win->mouse.x <= 1296 && win->mouse.y <= 823 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        i = 1;
    if (i == 1)
        draw(win->window, menu->info_two->sprite);
    if (win->mouse.x >= 611 && win->mouse.y >= 787
        && win->mouse.x <= 723 && win->mouse.y <= 823 && i == 1 && i == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        i = 0;
}