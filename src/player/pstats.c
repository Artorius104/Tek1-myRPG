/*
** EPITECH PROJECT, 2021
** pstats
** File description:
** pstats
*/

#include "rpg.h"

rect_t *create_pstat_rect(void)
{
    rect_t *obj = malloc(sizeof(rect_t));

    obj->rect = sfRectangleShape_create();
    sfColor outcolor = sfColor_fromRGBA(0, 0, 0, 255);
    sfColor incolor = sfColor_fromRGBA(0, 0, 0, 0);
    obj->size.x = 300;
    obj->size.y = 30;
    sfRectangleShape_setSize(obj->rect, obj->size);
    sfRectangleShape_setOutlineColor(obj->rect, outcolor);
    sfRectangleShape_setFillColor(obj->rect, incolor);
    sfRectangleShape_setOutlineThickness(obj->rect, 1);
    obj->pos.x = 1550;
    return obj;
}

void draw_lifebarre(pstats_t *stats, window_t *win)
{
    stats->rect->pos.y = 20;
    if (stats->life <= 0)
        stats->life = 0;
    sfRectangleShape_setPosition(stats->rect->rect, stats->rect->pos);
    stats->rect->size.x = (300 * stats->life) / stats->max_life;
    sfColor outcolor = sfColor_fromRGBA(0, 0, 0, 0);
    sfColor incolor = sfColor_fromRGBA(139, 0, 0, 255);
    sfRectangleShape_setSize(stats->rect->rect, stats->rect->size);
    sfRectangleShape_setOutlineColor(stats->rect->rect, outcolor);
    sfRectangleShape_setFillColor(stats->rect->rect, incolor);
    sfRectangleShape_setOutlineThickness(stats->rect->rect, 1);
    sfRenderWindow_drawRectangleShape(win->window, stats->rect->rect, NULL);
    outcolor = sfColor_fromRGBA(0, 0, 0, 255);
    incolor = sfColor_fromRGBA(0, 0, 0, 0);
    stats->rect->size.x = 300;
    sfRectangleShape_setSize(stats->rect->rect, stats->rect->size);
    sfRectangleShape_setOutlineColor(stats->rect->rect, outcolor);
    sfRectangleShape_setFillColor(stats->rect->rect, incolor);
    sfRectangleShape_setOutlineThickness(stats->rect->rect, 3);
    sfRenderWindow_drawRectangleShape(win->window, stats->rect->rect, NULL);
}

void draw_xp(pstats_t *stats, window_t *win)
{
    stats->dmg = stats->lvl;
    stats->armor = stats->lvl / 3;
    stats->rect->pos.y = 70;
    sfRectangleShape_setPosition(stats->rect->rect, stats->rect->pos);
    stats->rect->size.x = (300 * stats->xp) / (stats->lvl * 2);
    sfColor outcolor = sfColor_fromRGBA(0, 0, 0, 0);
    sfColor incolor = sfColor_fromRGBA(0, 128, 0, 255);
    sfRectangleShape_setSize(stats->rect->rect, stats->rect->size);
    sfRectangleShape_setOutlineColor(stats->rect->rect, outcolor);
    sfRectangleShape_setFillColor(stats->rect->rect, incolor);
    sfRectangleShape_setOutlineThickness(stats->rect->rect, 1);
    sfRenderWindow_drawRectangleShape(win->window, stats->rect->rect, NULL);
    outcolor = sfColor_fromRGBA(0, 0, 0, 255);
    incolor = sfColor_fromRGBA(0, 0, 0, 0);
    stats->rect->size.x = 300;
    sfRectangleShape_setSize(stats->rect->rect, stats->rect->size);
    sfRectangleShape_setOutlineColor(stats->rect->rect, outcolor);
    sfRectangleShape_setFillColor(stats->rect->rect, incolor);
    sfRectangleShape_setOutlineThickness(stats->rect->rect, 3);
    sfRenderWindow_drawRectangleShape(win->window, stats->rect->rect, NULL);
}

pstats_t *init_pstats(void)
{
    pstats_t *stat = malloc(sizeof(pstats_t));

    stat->lvl = 1;
    stat->max_life = 90 + 10 * stat->lvl;
    stat->life = stat->max_life;
    stat->lvl_up = create_object("image/lvl_up.png", 540, 150);
    stat->lvl_up = init_rect(stat->lvl_up, 900, 339, 0);
    stat->rect = create_pstat_rect();
    stat->lvl_up->clock = sfClock_create();
    stat->dmg = 5 * stat->lvl;
    stat->armor = 5 * stat->lvl;
    stat->launch_lvlup = 0;
    stat->xp = 0;
    return stat;
}

pstats_t *update_stats(window_t *win, pstats_t *stats)
{
    if (stats->xp == stats->lvl * 2) {
        sfSound_play(win->sound->list[3]);
        stats->launch_lvlup = 1;
        stats->xp = 0;
        stats->lvl++;
        stats->max_life = 90 + 10 * stats->lvl;
        stats->life = stats->max_life;
    }
    if (stats->launch_lvlup == 110)
        stats->launch_lvlup = 0;
    if (stats->launch_lvlup != 0) {
        animation(stats->lvl_up, 900, 5400, 100.0);
        draw(win->window, stats->lvl_up->sprite);
        stats->launch_lvlup++;
    }
    stats->max_life = 90 + 10 * stats->lvl;
    draw_lifebarre(stats, win);
    draw_xp(stats, win);
    return stats;
}