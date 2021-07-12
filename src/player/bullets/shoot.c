/*
** EPITECH PROJECT, 2021
** shoot
** File description:
** shoot
*/

#include "rpg.h"

player_t *bullet_speed(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->weapon->clock);

    if ((time.microseconds / (player->weapon->ms * 1000.0)) > 1) {
        player->weapon->canshoot = 1;
        sfClock_restart(player->weapon->clock);
    }
    return player;
}

player_t *get_bullet_dir(player_t *player, window_t *win)
{
    if (win->mouse.x < 990 && win->mouse.y >= 360 && win->mouse.y <= 720)
        player->shootdir = 1;
    if (win->mouse.x > 990 && win->mouse.y >= 360 && win->mouse.y <= 720)
        player->shootdir = 2;
    if (win->mouse.y < 450 && win->mouse.x >= 640 && win->mouse.x <= 1280)
        player->shootdir = 3;
    if (win->mouse.y > 630 && win->mouse.x >= 640 && win->mouse.x <= 1280)
        player->shootdir = 4;
    return bullet_speed(player);
}

void move_bullets(player_t *player, int i)
{
    if (player->shoot[i]->direction == 1)
        player->shoot[i]->pos.x -= 25;
    if (player->shoot[i]->direction == 2)
        player->shoot[i]->pos.x += 25;
    if (player->shoot[i]->direction == 3)
        player->shoot[i]->pos.y -= 25;
    if (player->shoot[i]->direction == 4)
        player->shoot[i]->pos.y += 25;
    animat_bullet(player->shoot[i], player->shoot[i]->anim,
    player->shoot[i]->anim * 6, 130);
    destroy_bullet(player, i);
}

player_t *get_bullet(player_t *player, int i)
{
    sfVector2f pos = player->object->pos;
    if (player->shootdir == 1) {
        player->shoot[i] = create_bullet("image/l_bul.png", player, 960, 470);
        player->shoot[i] = init_bullet_rect(player->shoot[i], 70, 55, 55);
        player->shoot[i]->anim = 70;
    } else if (player->shootdir == 2) {
        player->shoot[i] = create_bullet("image/l_bul.png", player, 955, 470);
        player->shoot[i] = init_bullet_rect(player->shoot[i], 70, 55, 0);
        player->shoot[i]->anim = 70;
    }
    if (player->shootdir == 3) {
        player->shoot[i] = create_bullet("image/l_bul.png", player, 965, 455);
        player->shoot[i] = init_bullet_rect(player->shoot[i], 55, 70, 110);
        player->shoot[i]->anim = 55;
    } else if (player->shootdir == 4) {
        player->shoot[i] = create_bullet("image/l_bul.png", player, 963, 470);
        player->shoot[i] = init_bullet_rect(player->shoot[i], 55, 70, 180);
        player->shoot[i]->anim = 55;
    }
    return player;
}

void shoot(player_t *player, window_t *window)
{
    player = get_bullet_dir(player, window);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && player->weapon->canshoot == 1 && player->inv->display != 1) {
        sfSound_play(window->sound->list[1]);
        for (int i = 0; i < 10; i++)
            if (player->shoot[i] == NULL && window->quest->mod == 3) {
                player->weapon->canshoot = 0;
                player = get_bullet(player, i);
                break;
            }
    }
    for (int i = 0; i < 10; i++)
        if (player->shoot[i] != NULL) {
            move_bullets(player, i);
            if (player->shoot[i] != NULL) {
                sfSprite_setPosition(player->shoot[i]->sprite,
                player->shoot[i]->pos);
                draw(window->window, player->shoot[i]->sprite);
            }
        }
}