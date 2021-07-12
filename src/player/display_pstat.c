/*
** EPITECH PROJECT, 2021
** display_pstart
** File description:
** display_pstart
*/

#include "rpg.h"

void display_life(window_t *win, player_t *player)
{
    sfText_setCharacterSize(player->stat_txt->text, 30);
    sfText_setColor(player->stat_txt->text, sfColor_fromRGB(139, 0, 0));
    player->stat_txt->pos.x = 1380;
    player->stat_txt->pos.y = 16;
    sfText_setString(player->stat_txt->text, my_itoa(player->stats->life));
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
    player->stat_txt->pos.x = 1440;
    player->stat_txt->pos.y = 16;
    sfText_setString(player->stat_txt->text, "/");
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
    player->stat_txt->pos.x = 1470;
    player->stat_txt->pos.y = 16;
    sfText_setString(player->stat_txt->text, my_itoa(player->stats->max_life));
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
}

void display_xp(window_t *win, player_t *player)
{
    sfText_setCharacterSize(player->stat_txt->text, 30);
    sfText_setColor(player->stat_txt->text, sfColor_fromRGB(0, 132, 0));
    player->stat_txt->pos.x = 1420;
    player->stat_txt->pos.y = 67;
    sfText_setString(player->stat_txt->text, my_itoa(player->stats->xp));
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
    player->stat_txt->pos.x = 1460;
    player->stat_txt->pos.y = 67;
    sfText_setString(player->stat_txt->text, "/");
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
    player->stat_txt->pos.x = 1490;
    player->stat_txt->pos.y = 67;
    sfText_setString(player->stat_txt->text, my_itoa(player->stats->lvl * 2));
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
}

void display_lvl(window_t *win, player_t *player)
{
    sfText_setCharacterSize(player->stat_txt->text, 50);
    sfText_setColor(player->stat_txt->text, sfColor_fromRGB(200, 200, 200));
    player->stat_txt->pos.x = 440;
    player->stat_txt->pos.y = 390;
    sfText_setString(player->stat_txt->text, "lvl:");
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
    player->stat_txt->pos.x = 530;
    player->stat_txt->pos.y = 390;
    sfText_setString(player->stat_txt->text, my_itoa(player->stats->lvl));
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
}

void display_pstart(window_t *win, player_t *player)
{
    draw(win->window, player->pstat_page->sprite);
    display_lvl(win, player);
    sfText_setCharacterSize(player->stat_txt->text, 60);
    sfText_setColor(player->stat_txt->text, sfColor_fromRGB(200, 200, 200));
    player->stat_txt->pos.x = 440;
    player->stat_txt->pos.y = 465;
    sfText_setString(player->stat_txt->text, my_itoa(player->speed));
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
    player->stat_txt->pos.x = 440;
    player->stat_txt->pos.y = 585;
    sfText_setString(player->stat_txt->text, my_itoa(player->stats->armor));
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
    player->stat_txt->pos.x = 440;
    player->stat_txt->pos.y = 705;
    sfText_setString(player->stat_txt->text, my_itoa(player->stats->dmg));
    sfText_setPosition(player->stat_txt->text, player->stat_txt->pos);
    sfRenderWindow_drawText(win->window, player->stat_txt->text, NULL);
}

void display_xp_life(window_t *win, player_t *player)
{
    display_life(win, player);
    display_xp(win, player);
}