/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-julien.de-waele
** File description:
** lose.c
*/

#include "rpg.h"

lose_t *init_lose(void)
{
    lose_t *lose = malloc(sizeof(lose_t));
    sfVector2f pos = {50.0, 67.0};

    lose->game_over = create_object("image/gameover.png", 0, 0);
    lose->game_over = init_rect(lose->game_over, 0, 1080, 0);
    lose->skin = create_object("image/lose_skin.png", 960, -300);
    lose->exit = create_object("image/exitgameover.png", 138, 870);
    lose->home = create_object("image/restartgameover.png", 1403, 878);
    sfSprite_setColor(lose->exit->sprite,
    sfColor_fromRGBA(255, 255, 255, 0));
    sfSprite_setColor(lose->home->sprite,
    sfColor_fromRGBA(255, 255, 255, 0));
    sfSprite_setOrigin(lose->skin->sprite, pos);
    return lose;
}

void exit_or_restart(window_t *win, lose_t *lose, int exit_home)
{
    if (exit_home >= 254) {
        if (win->mouse.x >= lose->exit->pos.x
            && win->mouse.x <= lose->exit->pos.x + 206
            && win->mouse.y >= lose->exit->pos.y
            && win->mouse.y <= lose->exit->pos.y + 70
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sfRenderWindow_close(win->window);
        if (win->mouse.x >= lose->home->pos.x
            && win->mouse.x <= lose->home->pos.x + 349
            && win->mouse.y >= lose->home->pos.y
            && win->mouse.y <= lose->home->pos.y + 59
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfRenderWindow_close(win->window);
            main();
        }
    }
}

void draw_lose(window_t *win, lose_t *lose)
{
    sfSprite_setPosition(lose->skin->sprite, lose->skin->pos);
    draw(win->window, lose->game_over->sprite);
    draw(win->window, lose->skin->sprite);
    draw(win->window, lose->exit->sprite);
    draw(win->window, lose->home->sprite);
}

void change_fade_color(window_t *win, lose_t *lose, int exit_home)
{
    sfSprite_setColor(lose->exit->sprite,
    sfColor_fromRGBA(255, 255, 255, exit_home));
    sfSprite_setColor(lose->home->sprite,
    sfColor_fromRGBA(255, 255, 255, exit_home));
}

void do_lose(window_t *win, lose_t *lose)
{
    static int width = -200;
    static int exit_home = -400;

    if (width <= 1920)
        width += 10;
    if (width >= 0) {
        lose->game_over->rect.width = width;
        sfSprite_setTextureRect(lose->game_over->sprite, lose->game_over->rect);
    }
    if (lose->skin->pos.y <= 1200) {
        lose->skin->pos.y += 7;
        sfSprite_rotate(lose->skin->sprite, 5.0);
    }
    if (exit_home < 254)
        exit_home += 3;
    if (exit_home >= 0)
        change_fade_color(win, lose, exit_home);
    exit_or_restart(win, lose, exit_home);
    draw_lose(win, lose);
    transition(win);
}