/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "rpg.h"

void events(window_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
    }
}

pbl_t *init_game(void)
{
    pbl_t *game = malloc(sizeof(pbl_t));

    game->menu = create_mm_sprites();
    game->player = create_player();
    game->ground = create_map("./image/res_map/grounds.png");
    game->tp = create_teleport("./image/teleport.png");
    game->tp_clock = sfClock_create();
    game->lvl = create_level();
    game->lose = init_lose();
    return game;
}

int main(void)
{
    window_t *window = create_window();
    pbl_t *game = init_game();

    srand(time(NULL));
    window->map_pos = game->lvl->spawns[game->lvl->lvl];
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_clear(window->window, sfBlack);
        events(window);
        mode(game, window);
        sfRenderWindow_display(window->window);
    }
    sfMusic_destroy(window->sound->music);
    sfRenderWindow_destroy(window->window);
    return 0;
}