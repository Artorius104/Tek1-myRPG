/*
** EPITECH PROJECT, 2021
** controle_sound.c
** File description:
** controle sound
*/

#include "rpg.h"

void controle_menu_sound(object_l *menu, window_t *win)
{
    win->sound_m->rect.width = 766 + (3.85 * win->snd);
    sfSprite_setTextureRect(win->sound_m->sprite, win->sound_m->rect);
    if (win->mouse.x >= 646 && win->mouse.x <= 691
        && win->mouse.y >= 683 && win->mouse.y <= 697
        && win->snd > 0 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        win->snd--;
    if (win->mouse.x >= 1227 && win->mouse.x <= 1270
        && win->mouse.y >= 670 && win->mouse.y <= 711
        && win->snd < 100 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        win->snd++;
    draw(win->window, win->sound_m->sprite);
}

void controle_game_sound(object_l *menu, window_t *win)
{
    win->sound_g->rect.width = 780 + (3.66 * win->snd);
    sfSprite_setTextureRect(win->sound_g->sprite, win->sound_g->rect);
    if (win->mouse.x >= 694 && win->mouse.x <= 718
        && win->mouse.y >= 425 && win->mouse.y <= 439
        && win->snd > 0 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        win->snd--;
    if (win->mouse.x >= 1205 && win->mouse.x <= 1235
        && win->mouse.y >= 416 && win->mouse.y <= 452
        && win->snd < 100 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        win->snd++;
    draw(win->window, win->sound_g->sprite);
}