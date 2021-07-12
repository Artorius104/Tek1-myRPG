/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-julien.de-waele
** File description:
** create_main_menu.c
*/

#include "rpg.h"

object_l *create_mm_sprites(void)
{
    object_l *menu = malloc(sizeof(object_l));
    menu->starback = create_object("./image/backstar.png", 0, 0);
    menu->mnlunar = create_object("./image/mn_lunar.png", 0, 0);
    menu->exit = create_object("./image/exit.png", -90, 0);
    menu->info = create_object("./image/info.png", -90, 0);
    menu->param = create_object("./image/param.png", -90, 0);
    menu->start = create_object("./image/start.png", 0, 0);
    menu->bigstart = create_object("./image/bigstart.png", 0, 0);
    menu->sure = create_object("./image/exitpause.png", 0, 0);
    menu->menuparam = create_object("./image/parampause.png", 0, 0);
    menu->info_one = create_object("./image/info1.png", 0, 0);
    menu->info_two = create_object("./image/info2.png", 0, 0);
    menu->mod = 0;
    return menu;
}

void draw_main_menu(object_l *menu, window_t *win)
{
    draw(win->window, menu->starback->sprite);
    draw(win->window, menu->mnlunar->sprite);
    draw(win->window, menu->exit->sprite);
    draw(win->window, menu->info->sprite);
    draw(win->window, menu->param->sprite);
}