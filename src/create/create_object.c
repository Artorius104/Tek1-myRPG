/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** create_object
*/

#include "rpg.h"

object_t *create_object(char *pth, int x, int y)
{
    object_t *object = malloc(sizeof(object_t));

    object->texture = sfTexture_createFromFile(pth , NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, 0);
    object->pos.x = x;
    object->pos.y = y;
    sfSprite_setPosition(object->sprite, object->pos);
    object->scale.x = 1;
    object->scale.y = 1;
    sfSprite_setScale(object->sprite, object->scale);
    object->plus = 207;
    object->open = 0;
    object->is_closed = 0;
    return object;
}

object_t *init_rect(object_t *object, int width, int height, int top)
{
    object->rect.width = width;
    object->rect.height = height;
    object->rect.top = top;
    object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
    return object;
}

object_t *init_pos(object_t *object, int x, int y)
{
    object->pos.x = x;
    object->pos.y = y;
    sfSprite_setPosition(object->sprite, object->pos);
    return object;
}

void animation(object_t *object, int mv, int lim, float ms)
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

en_list *create_en_object(int lvl, en_list *list)
{
    int random_int = rand() % 100;

    if (random_int < 70) {
        list->lvl = lvl;
        list->speed = 5;
        list->life = 80 + 5 * lvl;
        list->dmg = 10 + 2 * lvl;
        list->object = create_object("image/blueghost.png", 0, 0);
    } else {
        list->lvl = lvl;
        list->speed = 3;
        list->life = 110 + 10 * lvl;
        list->dmg = 15 + 3 * lvl;
        list->object = create_object("image/whiteghost.png", 0, 0);
    }
    list->object->clock = sfClock_create();
    list->object = init_rect(list->object, 96, 96, 2);
    list->can_attack = 1;
    list->attack_clock = sfClock_create();
    return list;
}