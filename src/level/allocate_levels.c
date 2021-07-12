/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-myrpg-julien.de-waele
** File description:
** allocate_level.c
*/

#include "rpg.h"

level_t *create_level_memory(void)
{
    level_t *lvl = malloc(sizeof(level_t));

    lvl->lvl = 0;
    lvl->spawns = malloc(sizeof(sfVector2f) * 12);
    lvl->warps = malloc(sizeof(sfVector2f) * 12);
    lvl->maps = malloc(sizeof(char **) * 12);
    lvl->maps[11] = NULL;
    return lvl;
}