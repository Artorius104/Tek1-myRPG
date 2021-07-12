/*
** EPITECH PROJECT, 2021
** mode
** File description:
** mode
*/

#include "rpg.h"

void game_loop(pbl_t *game, window_t *win)
{
    my_fps(win);
    draw_ground(win, game, game->lvl);
    if (sfKeyboard_isKeyPressed(sfKeyO) == sfTrue
        && game->player->inv->display != 1 && win->mod == 1)
        launch_transition(win, 3);
    if (game->lvl->lvl != 0)
        mv_ennemies(win, game->lvl->ennemy[game->lvl->lvl], game->player);
    shoot(game->player, win);
    animate_player(game->player, win, game);
    inventory_display(game->player, win);
    draw_minimap(win, game->lvl, game->player);
    draw_quest(win, win->quest);
    if (game->player->stats->life <= 0)
        launch_transition(win, 2);
    else
        lvl_transition(win, game->lvl, game->player, game);
    transition(win);
}

void pause_menu(pbl_t *game, window_t *win)
{
    draw(win->window, win->setting->sprite);
    controle_game_sound(game->menu, win);
    if (win->mouse.x >= 680 && win->mouse.x <= 758
        && win->mouse.y >= 737 && win->mouse.y <= 783
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        sfRenderWindow_close(win->window);
    if (win->mouse.x >= 1188 && win->mouse.x <= 1247
        && win->mouse.y >= 737 && win->mouse.y <= 780
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        launch_transition(win, 1);
    transition(win);
}

void mode(pbl_t *game, window_t *win)
{
    win->mouse = sfMouse_getPositionRenderWindow(win->window);
    for (int i = 0; i < 12; i++)
        sfSound_setVolume(win->sound->list[i], win->snd);
    sfMusic_setVolume(win->sound->music, win->snd);
    if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
        sfRenderWindow_close(win->window);
    if (win->mod == 0)
        main_menu(game->menu, win);
    if (win->mod == 1)
        game_loop(game, win);
    if (win->mod == 2)
        do_lose(win, game->lose);
    if (win->mod == 3)
        pause_menu(game, win);
    if (win->mod == 4) {
        draw(win->window, win->win_screen->sprite);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sfRenderWindow_close(win->window);
    }
}