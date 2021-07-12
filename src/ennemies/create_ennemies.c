/*
** EPITECH PROJECT, 2021
** create_ennemies
** File description:
** create_ennemies
*/

#include "rpg.h"

ennemy_t *go_next(ennemy_t *ennemy)
{
    en_list *tmp = ennemy->list;

    ennemy->list->next = malloc(sizeof(en_list));
    ennemy->list = ennemy->list->next;
    ennemy->list->prev = tmp;
    return ennemy;
}

ennemy_t *create_en_lifebarre(ennemy_t *ennemy)
{
    ennemy->txt = create_text2("c'est rien cest la rue", 0, 0, 15);
    ennemy->rect = malloc(sizeof(rect_t));
    ennemy->rect->rect = sfRectangleShape_create();
    sfColor outcolor = sfColor_fromRGBA(8, 98, 175, 200);
    sfColor incolor = sfColor_fromRGBA(8, 98, 175, 200);
    ennemy->rect->size.x = 50;
    ennemy->rect->size.y = 10;
    sfRectangleShape_setSize(ennemy->rect->rect, ennemy->rect->size);
    sfRectangleShape_setOutlineColor(ennemy->rect->rect, outcolor);
    sfRectangleShape_setFillColor(ennemy->rect->rect, incolor);
    sfRectangleShape_setOutlineThickness(ennemy->rect->rect, 1);
    return ennemy;
}

ennemy_t *init_ennemies(void)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    ennemy = create_en_lifebarre(ennemy);
    ennemy->list = malloc(sizeof(en_list));
    ennemy->list->prev = NULL;
    ennemy->start = ennemy->list;
    return ennemy;
}

ennemy_t *create_ennemies(level_t *lvl, int nm, int x_spawn, int y_spawn)
{
    ennemy_t *ennemy = init_ennemies();

    for (int i = 1, nb = 0; lvl->maps[lvl->lvl][i] != NULL; i++) {
        for (int t = 0; lvl->maps[lvl->lvl][i][t] != '\0'; t++) {
            if (rand() % 1000 < nm && lvl->maps[lvl->lvl][i][t] == 'F') {
                ennemy->list = create_en_object(lvl->lvl, ennemy->list);
                ennemy->list->object = init_pos(ennemy->list->object,
                    t * 96 + x_spawn - 946, i * 96 + y_spawn - 474);
                ennemy = go_next(ennemy);
            }
        }
    }
    ennemy->list->next = NULL;
    ennemy->list = ennemy->start;
    return ennemy;
}

ennemy_t **create_all_ennemies(level_t *lvl)
{
    ennemy_t **all_ennemies = malloc(sizeof(ennemy_t *) * 12);

    all_ennemies[0] = create_ennemies(lvl, 0, 0.0, 0.0);
    return all_ennemies;
}