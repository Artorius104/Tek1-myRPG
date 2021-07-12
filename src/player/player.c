/*
** EPITECH PROJECT, 2021
** player
** File description:
** player
*/

#include "rpg.h"

void player_animation(object_t *object, int mv, int lim, float ms)
{
    sfTime time = sfClock_getElapsedTime(object->clock);
    if ((time.microseconds / (ms * 1000.0)) > 1) {
        object->rect.left += mv;
        sfClock_restart(object->clock);
    }
    if (object->rect.left >= lim)
        object->rect.left = 0;
}

player_t *get_direction(player_t *player, window_t *win)
{
    if (win->mouse.x < 990 && win->mouse.y >= 360 && win->mouse.y <= 720)
        player->direction = 1;
    if (win->mouse.x > 990 && win->mouse.y >= 360 && win->mouse.y <= 720)
        player->direction = 2;
    if (win->mouse.y < 450 && win->mouse.x >= 640 && win->mouse.x <= 1280)
        player->direction = 3;
    if (win->mouse.y > 630 && win->mouse.x >= 640 && win->mouse.x <= 1280)
        player->direction = 4;
    return player;
}

player_t *get_run_stand(player_t *player)
{
    if (player->direction == 1)
        player->object->rect.top = 134;
    if (player->direction == 2)
        player->object->rect.top = 268;
    if (player->direction == 3)
        player->object->rect.top = 402;
    if (player->direction == 4)
        player->object->rect.top = 0;
    if (player->direction == -1)
        player->object->rect.left = 100;
    if (player->direction == -2)
        player->object->rect.left = 100;
    if (player->direction == -3)
        player->object->rect.left = 100;
    if (player->direction == -4)
        player->object->rect.left = 100;
    return player;
}

void mv_win(player_t *player, window_t *win, pbl_t * game)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue) {
        if (collision_with_wall(game, win, 0, player->speed) == 1)
            return;
        win->map_pos.y += player->speed;
        win->mvmnt.y += player->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue) {
        if (collision_with_wall(game, win, player->speed, 0) == 1)
            return;
        win->map_pos.x += player->speed;
        win->mvmnt.x += player->speed;
    }
    return mv_win2(player, win, game);
}

void animate_player(player_t *player, window_t *win, pbl_t * game)
{
    if (win->quest->mod == 3)
        player = get_direction(player, win);
    player = get_run_stand(player);
    sfSprite_setTextureRect(player->object->sprite, player->object->rect);
    if (win->quest->mod == 3 && (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue
        || sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue
        || sfKeyboard_isKeyPressed(sfKeyS) == sfTrue
        || sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) && win->l_state == 0 ) {
        player_animation(player->object, 100, player->lim, 100);
        mv_win(player, win, game);
    } else if (player->direction > 0) {
        player->direction *= -1;
        player = get_run_stand(player);
    }
    draw_chests(win, game->lvl, player);
    player->stats = update_stats(win, player->stats);
    display_xp_life(win, player);
    player = heal(win, player->orb, player);
    sfSprite_setPosition(player->object->sprite, player->object->pos);
    draw(win->window, player->object->sprite);
}