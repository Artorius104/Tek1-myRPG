/*
** EPITECH PROJECT, 2021
** ennemies hitbox
** File description:
** ennemies hitbox
*/

#include "rpg.h"

int shoot_hb(ennemy_t *ennemy, player_t *player, int i)
{
    if (player->shoot[i]->anim == 70
        && player->shoot[i]->pos.x < ennemy->list->object->pos.x + 96
        && player->shoot[i]->pos.x + 70 > ennemy->list->object->pos.x
        && player->shoot[i]->pos.y < ennemy->list->object->pos.y + 96
        && player->shoot[i]->pos.y + 55 > ennemy->list->object->pos.y)
        return 1;
    if (player->shoot[i]->anim == 55
        && player->shoot[i]->pos.x < ennemy->list->object->pos.x + 96
        && player->shoot[i]->pos.x + 55 > ennemy->list->object->pos.x
        && player->shoot[i]->pos.y < ennemy->list->object->pos.y + 96
        && player->shoot[i]->pos.y + 70 > ennemy->list->object->pos.y)
        return 1;
    return 0;
}

void draw_en_lifebarre(window_t *win, ennemy_t *ennemy)
{
    ennemy->txt->pos.x = ennemy->list->object->pos.x + 20;
    ennemy->txt->pos.y = ennemy->list->object->pos.y - 30;
    sfText_setString(ennemy->txt->text, "lvl:");
    sfText_setPosition(ennemy->txt->text, ennemy->txt->pos);
    sfRenderWindow_drawText(win->window, ennemy->txt->text, NULL);
    ennemy->txt->pos.x = ennemy->list->object->pos.x + 45;
    ennemy->txt->pos.y = ennemy->list->object->pos.y - 30;
    sfText_setString(ennemy->txt->text, my_itoa(ennemy->list->lvl + 1));
    sfText_setPosition(ennemy->txt->text, ennemy->txt->pos);
    sfRenderWindow_drawText(win->window, ennemy->txt->text, NULL);
    ennemy->rect->pos.x = ennemy->list->object->pos.x + 10;
    ennemy->rect->pos.y = ennemy->list->object->pos.y - 10;
    sfRectangleShape_setPosition(ennemy->rect->rect, ennemy->rect->pos);
    ennemy->rect->size.x = 50 * ennemy->list->life / 100;
    sfRectangleShape_setSize(ennemy->rect->rect, ennemy->rect->size);
    sfRenderWindow_drawRectangleShape(win->window, ennemy->rect->rect, NULL);
}

player_t *ennemy_attack(window_t *win, ennemy_t *ennemy, player_t *player)
{
    sfTime time = sfClock_getElapsedTime(ennemy->list->attack_clock);

    if ((time.microseconds / (1000000.0)) > 1) {
        ennemy->list->can_attack = 1;
        sfClock_restart(ennemy->list->attack_clock);
    }
    if (player->object->pos.x < ennemy->list->object->pos.x + 76
        && player->object->pos.x + 100 > ennemy->list->object->pos.x + 20
        && player->object->pos.y < ennemy->list->object->pos.y + 76
        && player->object->pos.y + 134 > ennemy->list->object->pos.y + 20
        && ennemy->list->can_attack == 1) {
            sfSound_play(win->sound->list[4]);
            player->stats->life -= ennemy->list->dmg - player->stats->armor;
            ennemy->list->can_attack = 0;
        }
    return player;
}

ennemy_t *ennemies_hb(window_t *win, ennemy_t *ennemy, player_t *player)
{
    int last_life = 0;

    for (int i = 0; i < 10; i++) {
        if (player->shoot[i] != NULL && shoot_hb(ennemy, player, i) == 1) {
            last_life = ennemy->list->life;
            ennemy->list->life -= player->weapon->dmg + player->stats->dmg;
            player->shoot[i] = NULL;
            if (last_life > 0 && ennemy->list->life <= 0) {
                player->stats->xp++;
                player->orb = create_orb(player->orb, ennemy);
            }
        }
    }
    player = ennemy_attack(win, ennemy, player);
    return ennemy;
}