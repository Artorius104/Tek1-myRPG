/*
** EPITECH PROJECT, 2021
** create_text
** File description:
** create_text
*/

#include "rpg.h"

text_t *create_text(char *str, int x, int y, int size)
{
    text_t *text = malloc(sizeof(text_t));

    text->text = sfText_create();
    text->pos.x = x;
    text->pos.y = y;
    sfText_setString(text->text, str);
    sfText_setFont(text->text, sfFont_createFromFile("image/stat_f.otf"));
    sfText_setCharacterSize(text->text, size);
    sfText_setColor(text->text, sfColor_fromRGB(200, 200, 200));
    sfText_setPosition(text->text, text->pos);
    return text;
}

text_t *create_text2(char *str, int x, int y, int size)
{
    text_t *text = malloc(sizeof(text_t));

    text->text = sfText_create();
    text->pos.x = x;
    text->pos.y = y;
    sfText_setString(text->text, str);
    sfText_setFont(text->text, sfFont_createFromFile("image/stat_f.otf"));
    sfText_setCharacterSize(text->text, size);
    sfText_setColor(text->text, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(text->text, text->pos);
    return text;

}