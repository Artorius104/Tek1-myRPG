/*
** EPITECH PROJECT, 2021
** quest
** File description:
** quest
*/

#include "rpg.h"

quest_t *create_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->chatbox = create_object("image/chatbox.png", 0, 0);
    quest->eugena = create_object("image/eugena.png", 0, 0);
    quest->hello = create_object("image/hello.png", 0, 0);
    quest->abandon = create_object("image/abandon.png", 0, 0);
    quest->touches = create_object("image/touches.png", 0, 0);
    quest->goodluck = create_object("image/goodluck.png", 0, 0);
    quest->presse = create_object("image/presse.png", 0, 0);
    quest->pressenter = create_object("image/pressenter.png", 0, 0);
    quest->chatbox = init_rect(quest->chatbox, 1920, 1080, 0);
    quest->eugena = init_rect(quest->eugena, 1920, 1080, 0);
    quest->hello = init_rect(quest->hello, 47, 1080, 0);
    quest->abandon = init_rect(quest->abandon, 44, 1080, 0);
    quest->touches = init_rect(quest->touches, 48, 1080, 0);
    quest->goodluck = init_rect(quest->goodluck, 48, 1080, 0);
    quest->presse = init_rect(quest->presse, 1383, 1080, 0);
    quest->pressenter = init_rect(quest->pressenter, 1312, 1080, 0);
    quest->mod = 0;
    return quest;
}

void set_quest_rects(window_t *win, quest_t *quest)
{
    sfSprite_setTextureRect(quest->hello->sprite, quest->hello->rect);
    sfSprite_setTextureRect(quest->abandon->sprite, quest->abandon->rect);
    sfSprite_setTextureRect(quest->touches->sprite, quest->touches->rect);
    sfSprite_setTextureRect(quest->goodluck->sprite, quest->goodluck->rect);
    sfSprite_setTextureRect(quest->presse->sprite, quest->presse->rect);
    sfSprite_setTextureRect(quest->pressenter->sprite, quest->pressenter->rect);
}

void draw_questbox(window_t *win, quest_t *quest)
{
    if (quest->mod >= 0 && quest->mod <= 2) {
        set_quest_rects(win, quest);
        draw(win->window, quest->chatbox->sprite);
        draw(win->window, quest->eugena->sprite);
    }
    if (quest->mod == 1) {
        draw(win->window, quest->hello->sprite);
        draw(win->window, quest->abandon->sprite);
        draw(win->window, quest->presse->sprite);
    } else if (quest->mod == 2) {
        draw(win->window, quest->touches->sprite);
        draw(win->window, quest->goodluck->sprite);
        draw(win->window, quest->pressenter->sprite);
    }
}

void do_questmod2(window_t *win, quest_t *quest)
{
    if (quest->mod >= 0 && quest->mod <= 2
    && sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue) {
        sfSound_play(win->sound->list[5]);
        quest->mod = 3;
    }
    if (quest->touches->rect.width <= 1093 && quest->mod == 2)
        quest->touches->rect.width += 7;
    if (quest->goodluck->rect.width <= 169
        && quest->touches->rect.width >= 1093)
        quest->goodluck->rect.width += 7;
    if (quest->pressenter->rect.width <= 1654
        && quest->goodluck->rect.width >= 169)
        quest->pressenter->rect.width += 7;
    if (quest->pressenter->rect.width >= 1654
        && sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue) {
        sfSound_play(win->sound->list[5]);
        quest->mod = 3;
    }
    draw_questbox(win, quest);
}

void draw_quest(window_t *win, quest_t *quest)
{
    static int start = 0;

    if (start < 101)
        start += 2;
    if (start == 100)
        quest->mod = 1;
    if (quest->hello->rect.width <= 698 && quest->mod == 1)
        quest->hello->rect.width += 7;
    if (quest->hello->rect.width >= 698
        && quest->abandon->rect.width <= 1157)
        quest->abandon->rect.width += 7;
    if (quest->abandon->rect.width >= 1157
        && quest->presse->rect.width <= 1637)
        quest->presse->rect.width += 7;
    if (quest->presse->rect.width >= 1637 && quest->mod == 1
        && sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        sfSound_play(win->sound->list[5]);
        quest->mod = 2;
    }
    do_questmod2(win, quest);
}