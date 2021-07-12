/*
** EPITECH PROJECT, 2021
** init chests
** File description:
** init chests
*/

#include "rpg.h"

object_t **create_lvl_chests(level_t *lvl, int x_spawn, int y_spawn, int level)
{
    object_t **chests = NULL;
    int nb = 0;

    for (int i = 1; lvl->maps[level][i] != NULL; i++)
        for (int t = 0; lvl->maps[level][i][t] != '\0'; t++)
            if (lvl->maps[level][i][t] == '2')
                ++nb;
    chests = malloc(sizeof(object_t) * nb);
    nb = 0;
    for (int i = 1; lvl->maps[level][i] != NULL; i++)
        for (int t = 0; lvl->maps[level][i][t] != '\0'; t++)
            if (lvl->maps[level][i][t] == '2') {
                chests[nb] = create_object("image/chest.png",
                t * 96 + x_spawn - 55, i * 96 + y_spawn - 20);
                chests[nb]->clock = sfClock_create();
                chests[nb] = init_rect(chests[nb], 207, 130, 0);
                ++nb;
            }
    chests[nb] = NULL;
    return chests;
}

object_t ***create_all_chests(level_t *lvl)
{
    object_t ***chests = malloc(sizeof(object_t **) * 11);

    for (int i = 0; i < 11; i++)
        chests[i] = create_lvl_chests(lvl,
        lvl->spawns[i].x, lvl->spawns[i].y, i);
    return chests;
}

void anim_chest1(object_t *object)
{
    sfTime time = sfClock_getElapsedTime(object->clock);
    if ((time.microseconds / (200000.0)) > 1) {
        object->rect.left += object->plus;
        sfClock_restart(object->clock);
        if (object->rect.left >= 414 || object->rect.left <= 0)
            object->plus = object->plus * -1;
    }
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void anim_chest2(object_t *object)
{
    sfTime time = sfClock_getElapsedTime(object->clock);
    if ((time.microseconds / (200000.0)) > 1) {
        if (object->open == 1)
            object->rect.left += object->plus;
        sfClock_restart(object->clock);
        if (object->open == 0)
            object->rect.left += 207;
        if (object->rect.left > 1035)
            object->open = 1;
        if ((object->rect.left >= 2069 || object->rect.left <= 1035)
        && object->open == 1)
            object->plus = object->plus * -1;
    }
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void draw_chests(window_t *win, level_t *lvl, player_t *player)
{
    for (int i = 0; lvl->chests[lvl->lvl][i] != NULL && lvl->lvl != 0; i++) {
        if (lvl->chests[lvl->lvl][i]->is_closed == 1)
            anim_chest2(lvl->chests[lvl->lvl][i]);
        if (lvl->chests[lvl->lvl][i]->is_closed == 0)
            anim_chest1(lvl->chests[lvl->lvl][i]);
        draw(win->window, lvl->chests[lvl->lvl][i]->sprite);
        if (open_chest(win, lvl, player, i) == 1
        && lvl->chests[lvl->lvl][i]->is_closed == 0) {
            lvl->chests[lvl->lvl][i]->is_closed = 1;
            sfSound_play(win->sound->list[8]);
            player->inv = generate_weapon(player->inv);
        }
        lvl->chests[lvl->lvl][i]->pos.x += win->mvmnt.x;
        lvl->chests[lvl->lvl][i]->pos.y += win->mvmnt.y;
        sfSprite_setPosition(lvl->chests[lvl->lvl][i]->sprite,
        lvl->chests[lvl->lvl][i]->pos);
    }
}