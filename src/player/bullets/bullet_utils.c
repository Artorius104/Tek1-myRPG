/*
** EPITECH PROJECT, 2021
** shoot_2
** File description:
** shoot_2
*/

#include "rpg.h"

shoot_t *create_bullet(char *pth, player_t *player, int x, int y)
{
    shoot_t *object = malloc(sizeof(shoot_t));

    object->texture = sfTexture_createFromFile(pth , NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, 0);
    sfSprite_setPosition(object->sprite, object->pos);
    player->shootpos = player->object->pos;
    object->direction = player->shootdir;
    object->dmg = player->weapon->dmg;
    object->clock = sfClock_create();
    object->pos.x = x;
    object->pos.y = y;
    player->object->scale.x += 0.03;
    return object;
}

shoot_t *init_bullet_rect(shoot_t *object, int width, int height, int top)
{
    object->rect.width = width;
    object->rect.height = height;
    object->rect.top = top;
    object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
    return object;
}

player_t *destroy_bullet(player_t *player, int i)
{
    if (player->shoot[i]->pos.x <= player->shootpos.x - 370
        || player->shoot[i]->pos.x >= player->shootpos.x + 450
        || player->shoot[i]->pos.y <= player->shootpos.y - 370
        || player->shoot[i]->pos.y >= player->shootpos.y + 485) {
        player->shoot[i] = NULL;
    }
    return player;
}

void shake(player_t *player)
{
    sfVector2f pos = player->object->pos;
    static float mult_scale = 0.03;
    if (player->object->scale.x != 1) {
        player->object->scale.x += mult_scale;
        player->object->scale.y = player->object->scale.x;
        player->object->pos.x -= mult_scale * 50;
        player->object->pos.y -= mult_scale * 60;
    }
    if (player->object->scale.x >= 1.1)
        mult_scale *= -1;
    if (player->object->scale.x == 1) {
        player->object->pos.x = pos.x;
        player->object->pos.y = pos.y;
        mult_scale = 0.03;
    }
    sfSprite_setPosition(player->object->sprite, player->object->pos);
    sfSprite_setScale(player->object->sprite, player->object->scale);
}

void animat_bullet(shoot_t *object, int mv, int lim, float ms)
{
    sfTime time = sfClock_getElapsedTime(object->clock);
    if ((time.microseconds / (ms * 1000.0)) > 1) {
        object->rect.left += mv;
        sfClock_restart(object->clock);
    }
    if (object->rect.left >= lim)
        object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
}