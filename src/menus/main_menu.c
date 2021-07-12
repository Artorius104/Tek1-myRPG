/*
** EPITECH PROJECT, 2021
** main menu
** File description:
** main menu
*/

#include "rpg.h"

void move_utils(object_t *object, window_t *win, int y)
{
    if (win->mouse.x >= 0 && win->mouse.y >= y && win->mouse.x <= 204
        && win->mouse.y <= y + 86) {
        if (object->pos.x < 0)
            object->pos.x += 15;
    } else
        if (object->pos.x > -90)
            object->pos.x -= 15;
    sfSprite_setPosition(object->sprite, object->pos);
}

int icon_hb(window_t *win, int y)
{
    if (win->mouse.x >= 0 && win->mouse.y >= y && win->mouse.x <= 204
        && win->mouse.y <= y + 86
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        sfSound_play(win->sound->list[5]);
        return 1;
    }
    return 0;
}

void do_menu_mod(object_l *menu, window_t *win)
{
    if ((menu->mod == 1 || menu->mod == 2)
        && sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        menu->mod = 0;
    if (menu->mod == 1)
        my_info(menu, win);
    if (menu->mod == 2) {
        my_pause(menu, win);
        controle_menu_sound(menu, win);
    }
    if (menu->mod == 3) {
        draw(win->window, menu->sure->sprite);
        if (win->mouse.x >= 1072 && win->mouse.y >= 500
        && win->mouse.x <= 1287 && win->mouse.y <= 663 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sfRenderWindow_close(win->window);
        else if (win->mouse.x >= 673 && win->mouse.y >= 488
        && win->mouse.x <= 854 && win->mouse.y <= 668 &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            menu->mod = 0;
    }
}

void main_menu_conditions(object_l *menu, window_t *win)
{
    if (win->mouse.x >= 823 && win->mouse.y >= 803
        && win->mouse.x <= 1087 && win->mouse.y <= 890 && menu->mod == 0) {
        draw(win->window, menu->bigstart->sprite);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfSound_play(win->sound->list[5]);
            launch_transition(win, 1);
        }
    } else
        draw(win->window, menu->start->sprite);
    if (icon_hb(win, 158) == 1) {
        draw(win->window, menu->param->sprite);
        menu->mod = 3;
    }
    if (icon_hb(win, 282) == 1)
        menu->mod = 1;
    if (icon_hb(win, 408) == 1)
        menu->mod = 2;
    do_menu_mod(menu, win);
}

void main_menu(object_l *menu, window_t *win)
{
    draw(win->window, win->trans->sprite);
    draw_main_menu(menu, win);
    main_menu_conditions(menu, win);
    menu->starback->pos.x -= 3;
    if (menu->starback->pos.x <= -1920)
        menu->starback->pos.x = 0;
    sfSprite_setPosition(menu->starback->sprite, menu->starback->pos);
    if (menu->mod == 0) {
        move_utils(menu->exit, win, 158);
        move_utils(menu->info, win, 282);
        move_utils(menu->param, win, 408);
    }
    transition(win);
}