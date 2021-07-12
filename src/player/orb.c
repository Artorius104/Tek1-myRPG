/*
** EPITECH PROJECT, 2021
** orb
** File description:
** orb
*/

#include "rpg.h"

void is_space_pressed(window_t *win, object_t **orb, player_t *player, int i)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
        if (player->stats->life <= player->stats->max_life - 20) {
            player->stats->life += 20;
        } else if (player->stats->life > player->stats->max_life - 20
            && player->stats->life != player->stats->max_life)
            player->stats->life += player->stats->max_life
            - player->stats->life;
        sfSound_play(win->sound->list[0]);
        orb[i] = NULL;
    }
}

player_t *update_orb_pos(window_t *win, object_t **orb, player_t *player)
{
    player->press_space = init_pos(player->press_space,
    player->object->pos.x - 20, player->object->pos.y - 20);
    for (int i = 0; i < 5; ++i)
        if (orb[i] != NULL) {
            orb[i]->pos.x += win->mvmnt.x;
            orb[i]->pos.y += win->mvmnt.y;
            sfSprite_setPosition(orb[i]->sprite, orb[i]->pos);
        }
    return player;
}

player_t *heal(window_t *win, object_t **orb, player_t *player)
{
    for (int i = 0; i < 5; i++)
        if (orb[i] != NULL) {
            draw(win->window, orb[i]->sprite);
            animation(orb[i], 80, 1360, 200);
        }
    for (int i = 0; i < 5 && orb[i] != NULL; ++i)
        if (player->object->pos.x < orb[i]->pos.x + 80
            && player->object->pos.x + 100 > orb[i]->pos.x
            && player->object->pos.y < orb[i]->pos.y + 60
            && player->object->pos.y + 134 > orb[i]->pos.y) {
                draw(win->window, player->press_space->sprite);
                is_space_pressed(win, orb, player, i);
            }
    player = update_orb_pos(win, orb, player);
    return player;
}

object_t **create_orb(object_t **orb, ennemy_t *ennemy)
{
    int random = rand() % 101;
    int spawn_orb = 0;

    if (random <= 30)
        spawn_orb = 1;
    for (int i = 0; i < 5 && spawn_orb == 1; ++i)
        if (orb[i] == NULL) {
            orb[i] = create_object("image/orb.png",
            ennemy->list->object->pos.x, ennemy->list->object->pos.y);
            orb[i] = init_rect(orb[i], 80, 60, 0);
            orb[i]->clock = sfClock_create();
            break;
        }
    return orb;
}