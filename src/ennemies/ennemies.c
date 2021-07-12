/*
** EPITECH PROJECT, 2021
** ennemies
** File description:
** ennemeis
*/

#include "rpg.h"

void draw_ennemies(window_t *win, ennemy_t *ennemy)
{
    while (ennemy->list->next->next != NULL) {
        if (ennemy->list->life > 0) {
            ennemy->list->object->pos.x += win->mvmnt.x;
            ennemy->list->object->pos.y += win->mvmnt.y;
            sfSprite_setPosition(ennemy->list->object->sprite,
            ennemy->list->object->pos);
            draw(win->window, ennemy->list->object->sprite);
            animation(ennemy->list->object, 96, 576, 200.0);
        }
        ennemy->list = ennemy->list->next;
    }
    win->mvmnt.x = 0;
    win->mvmnt.y = 0;
    ennemy->list = ennemy->start;
}

int check_agro_hb(ennemy_t *ennemy, player_t *player)
{
    if (player->object->pos.x + 100 > ennemy->list->object->pos.x - 300
        && player->object->pos.x < ennemy->list->object->pos.x + 396
        && player->object->pos.y + 134 > ennemy->list->object->pos.y - 300
        && player->object->pos.y < ennemy->list->object->pos.y + 396)
        return 1;
    return 0;
}

ennemy_t *set_direction(ennemy_t *ennemy, player_t *player)
{
    if (player->object->pos.y > ennemy->list->object->pos.y)
        ennemy->list->object->rect.top = 2;
    if (player->object->pos.y < ennemy->list->object->pos.y)
        ennemy->list->object->rect.top = 290;
    if (player->object->pos.x > ennemy->list->object->pos.x)
        ennemy->list->object->rect.top = 186;
    if (player->object->pos.x < ennemy->list->object->pos.x)
        ennemy->list->object->rect.top = 100;
    sfSprite_setTextureRect(ennemy->list->object->sprite,
    ennemy->list->object->rect);
    return ennemy;
}

ennemy_t *mvmnt(ennemy_t *ennemy, player_t *player)
{
    int x = player->object->pos.x - ennemy->list->object->pos.x;
    int y = player->object->pos.y - ennemy->list->object->pos.y;

    if (x < 0)
        x *= -1;
    if (y < 0)
        y *= -1;
    if (player->object->pos.x > ennemy->list->object->pos.x)
        ennemy->list->object->pos.x += ennemy->list->speed;
    if (player->object->pos.x < ennemy->list->object->pos.x)
        ennemy->list->object->pos.x -= ennemy->list->speed;
    if (player->object->pos.y + 23 > ennemy->list->object->pos.y)
        ennemy->list->object->pos.y += ennemy->list->speed;
    if (player->object->pos.y + 23 < ennemy->list->object->pos.y)
        ennemy->list->object->pos.y -= ennemy->list->speed;
    sfSprite_setPosition(ennemy->list->object->sprite,
    ennemy->list->object->pos);
    return ennemy;
}

void mv_ennemies(window_t *win, ennemy_t *ennemy, player_t *player)
{
    while (ennemy->list->next->next != NULL) {
        if (ennemy->list->life > 0 && check_agro_hb(ennemy, player) == 1) {
            ennemy = mvmnt(ennemy, player);
            ennemy = set_direction(ennemy, player);
            draw_en_lifebarre(win, ennemy);
            ennemy = ennemies_hb(win, ennemy, player);
        }
        ennemy->list = ennemy->list->next;
    }
    ennemy->list = ennemy->start;
    draw_ennemies(win, ennemy);
}