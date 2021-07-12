/*
** EPITECH PROJECT, 2021
** create_window
** File description:
** create_window
*/

#include "rpg.h"

window_t *create_window2(window_t *win)
{
    win->t_state = 0;
    win->t_mod = 0;
    win->l_state = 0;
    win->l_mod = 0;
    win->mvmnt.x = 0.0;
    win->mvmnt.y = 0.0;
    win->fps = 30;
    sfRenderWindow_setFramerateLimit(win->window, 30);
    win->quest = create_quest();
    win->sound_m = create_object("image/bar1.png", 0, 0);
    win->sound_g = create_object("image/bar2.png", 0, 0);
    win->sound_m = init_rect(win->sound_m, 766, 1080, 0);
    win->sound_g = init_rect(win->sound_g, 780, 1080, 0);
    win->snd = 100;
    win->setting = create_object("image/setting.png", 0, 0);
    win->win_screen = create_object("image/win.png", 666, 327);
    win->snd = 50.0;
    return win;
}

window_t *create_window(void)
{
    window_t *win = malloc(sizeof(window_t));

    sfVideoMode mode = {1920, 1080, 32};
    win->window = sfRenderWindow_create(mode, "SPACE RANGER", sfClose, NULL);
    win->mod = 0;
    win->trans = create_object("./image/transition.png", 0, 0);
    win->back = create_object("./image/back.jpg", 0, 0);
    win->trans->rect.width = 1920;
    win->trans->rect.height = 1080;
    win->transcolor = 0;
    win->trans->rect.top = 0;
    win->trans->rect.left = 0;
    sfSprite_setTextureRect(win->trans->sprite, win->trans->rect);
    win = create_window2(win);
    win->sound = init_audio();
    sfMusic_play(win->sound->music);
    return win;
}