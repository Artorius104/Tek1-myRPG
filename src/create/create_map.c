/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** create map
*/

#include "rpg.h"

sfSprite **create_chest(char *path)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * 2);
    sfTexture *texture = sfTexture_createFromFile(path , NULL);
    sfIntRect rect = {0, 0, 82, 88};

    for (int i = 0; i < 2; ++i) {
        sprites[i] = sfSprite_create();
        sfSprite_setTexture(sprites[i], texture, sfTrue);
        sfSprite_setTextureRect(sprites[i], rect);
        rect.left += 82;
    }
    return sprites;
}

sfSprite **create_teleport(char *path)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * 6);
    sfTexture *texture = sfTexture_createFromFile(path , NULL);
    sfIntRect rect = {0, 0, 256, 128};

    for (int i = 0; i < 5; ++i) {
        sprites[i] = sfSprite_create();
        sfSprite_setTexture(sprites[i], texture, sfTrue);
        sfSprite_setTextureRect(sprites[i], rect);
        rect.top += 128;
    }
    sprites[5] = NULL;
    return sprites;
}

sfSprite **create_map(char *path)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * 16);
    sfTexture *texture = sfTexture_createFromFile(path , NULL);
    sfIntRect rect = {0, 0, 96, 96};

    for (int i = 0; i < 16; ++i) {
        sprites[i] = sfSprite_create();
        sfSprite_setTexture(sprites[i], texture, sfTrue);
        sfSprite_setTextureRect(sprites[i], rect);
        rect.left += 96;
        if (rect.left == 768) {
            rect.left = 0;
            rect.top += 96;
        }
    }
    return sprites;
}