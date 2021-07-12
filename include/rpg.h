/*
** EPITECH PROJECT, 2020
** issam
** File description:
** .h
*/

#ifndef RPG_H_
#define RPG_H_

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio.h>
#include <time.h>
#include "my.h"

typedef struct object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f scale;
    int plus;
    int open;
    int is_closed;
}object_t;

typedef struct rect_s {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
}rect_t;

typedef struct text_s {
    sfText *text;
    sfVector2f pos;
}text_t;

typedef struct shoot_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int direction;
    sfClock *clock;
    sfIntRect rect;
    int anim;
    int dmg;
}shoot_t;

typedef struct weapon_s {
    sfClock *clock;
    int type;
    int ms;
    int canshoot;
    int dmg;
    int index;
    object_t *object;
}weapon_t;

typedef struct ennemis_l {
    struct ennemis_l *next;
    struct ennemis_l *prev;
    int can_attack;
    int lvl;
    int life;
    int speed;
    int dmg;
    sfClock *attack_clock;
    object_t *object;
}en_list;

typedef struct ennemy_s {
    en_list *list;
    en_list *start;
    rect_t *rect;
    text_t *txt;
}ennemy_t;

typedef struct chest_s {
    int id;
    int open;
}chest_t;

typedef struct level_s {
    char ***maps;
    sfVector2f *spawns;
    sfVector2f *warps;
    int lvl;
    ennemy_t **ennemy;
    object_t ***chests;
}level_t;

typedef struct pstats_s {
    object_t *lvl_up;
    rect_t *rect;
    int launch_lvlup;
    int max_life;
    int life;
    int lvl;
    int dmg;
    int armor;
    int xp;
}pstats_t;

typedef struct inventory_s {
    object_t *object;
    object_t *hotbar;
    object_t *stat_b;
    object_t *trash;
    weapon_t **items;
    rect_t *rect;
    rect_t *hotrect;
    rect_t *mini_rect;
    weapon_t *stock;
    text_t *stat_txt;
    int s_index;
    int s_index2;
    int prev_index;
    int is_swapping;
    int **slot_pos;
    int display;
    int index;
}inventory_t;

typedef struct quest_l {
    object_t *chatbox;
    object_t *eugena;
    object_t *hello;
    object_t *abandon;
    object_t *touches;
    object_t *goodluck;
    object_t *presse;
    object_t *pressenter;
    int mod;
}quest_t;

typedef struct sound_s {
    sfMusic *music;
    sfSound **list;
}sound_t;

typedef struct window_s {
    sfRenderWindow *window;
    quest_t *quest;
    sfEvent event;
    sfVector2i mouse;
    sfVector2f map_pos;
    sfVector2f mvmnt;
    int mod;
    char **map;
    char *pth;
    int fps;
    sound_t *sound;
    object_t *trans;
    object_t *back;
    object_t *sound_m;
    object_t *sound_g;
    object_t *setting;
    object_t *win_screen;
    float snd;
    int transcolor;
    int t_state;
    int t_mod;
    int l_state;
    int l_mod;
}window_t;

typedef struct object_list {
    object_t *starback;
    object_t *mnlunar;
    object_t *exit;
    object_t *info;
    object_t *param;
    object_t *start;
    object_t *bigstart;
    object_t *sure;
    object_t *menuparam;
    object_t *info_one;
    object_t *info_two;
    int mod;
}object_l;

typedef struct lose_s {
    object_t *game_over;
    object_t *skin;
    object_t *exit;
    object_t *home;
}lose_t;

typedef struct player_s {
    object_t *object;
    shoot_t **shoot;
    weapon_t *weapon;
    inventory_t *inv;
    pstats_t *stats;
    object_t **orb;
    object_t *press_space;
    object_t *pstat_page;
    text_t *stat_txt;
    int speed;
    int direction;
    int shootdir;
    sfVector2f shootpos;
    int lim;
}player_t;

typedef struct pbl_s {
    object_l *menu;
    player_t *player;
    level_t *lvl;
    lose_t *lose;
    sfSprite **ground;
    sfView *view;
    sfVector2f view_size;
    sfSprite **tp;
    sfClock *tp_clock;
}pbl_t;

window_t *create_window(void);
object_t *create_object(char *pth, int x, int y);
text_t *create_text(char *str, int x, int y, int size);
text_t *create_text2(char *str, int x, int y, int size);
object_t *init_rect(object_t *object, int width, int height, int top);
object_t *init_pos(object_t *object, int x, int y);
void animation(object_t *object, int mv, int lim, float ms);
int main(void);

void draw(sfRenderWindow *window, sfSprite *sprite);

/*MENU*/
object_l *create_mm_sprites(void);
void transition(window_t *win);
void launch_transition(window_t *win, int mod);
void main_menu(object_l *menu, window_t *win);
lose_t *init_lose(void);
void do_lose(window_t *win, lose_t *lose);
void draw_main_menu(object_l *menu, window_t *win);
quest_t *create_quest(void);
void draw_quest(window_t *win, quest_t *quest);
void my_pause(object_l *menu, window_t *win);
void my_fps(window_t *win);
void my_info(object_l *menu, window_t *win);
void controle_menu_sound(object_l *menu, window_t *win);
void controle_game_sound(object_l *menu, window_t *win);

/*PLAYER*/
player_t *create_player(void);
shoot_t *create_bullet(char *pth, player_t *player, int x, int y);
inventory_t *create_inventory(inventory_t *inv, sfVector2f pos);
inventory_t *generate_weapon(inventory_t *inv);
inventory_t *swap_items(inventory_t *inv, window_t *win);
player_t *put_rect(player_t *player, int nb);
weapon_t *create_glock(weapon_t *item, inventory_t *inv, int i);
weapon_t *create_rifle(weapon_t *item, inventory_t *inv, int i);
weapon_t *create_snipe(weapon_t *item, inventory_t *inv, int i);
player_t *destroy_bullet(player_t *player, int i);
shoot_t *init_bullet_rect(shoot_t *object, int width, int height, int top);
player_t *switch_weapons(inventory_t *inv, player_t *player, window_t *win);
object_t **create_orb(object_t **orb, ennemy_t *ennemy);
player_t *heal(window_t *win, object_t **orb, player_t *player);
pstats_t *init_pstats(void);
pstats_t *update_stats(window_t *win, pstats_t *stats);
void mv_win2(player_t *player, window_t *win, pbl_t * game);
void display_xp_life(window_t *win, player_t *player);
void display_pstart(window_t *win, player_t *player);
int collision_with_wall(pbl_t *game, window_t *win, int dirx, int diry);
void animate_player(player_t *player, window_t *win, pbl_t *game);
void animat_bullet(shoot_t *object, int mv, int lim, float ms);
void shoot(player_t *player, window_t *window);
void inventory_display(player_t *player, window_t *win);
void draw_inv_weapons(inventory_t *inv, window_t *win);
void draw_hot_weapons(inventory_t *inv, window_t *win);
void draw_minimap(window_t *win, level_t *lvl, player_t *player);
void shake(player_t *player);
void print_stats(inventory_t *inv, window_t *win);

/*ENNEMY*/
ennemy_t **create_all_ennemies(level_t *lvl);
ennemy_t *init_ennemies(void);
ennemy_t *ennemies_hb(window_t *win, ennemy_t *ennemy, player_t *player);
en_list *create_en_object(int lvl, en_list *list);
void draw_en_lifebarre(window_t *win, ennemy_t *ennemy);
void mv_ennemies(window_t *win, ennemy_t *ennemy, player_t *player);

/*CHESTS*/
object_t ***create_all_chests(level_t *lvl);
void draw_chests(window_t *win, level_t *lvl, player_t *player);
int open_chest(window_t *win, level_t *lvl, player_t *player, int i);

/*LEVEL*/
level_t *create_level_memory(void);
level_t *create_level(void);
void lvl_transition(window_t *win, level_t *lvl, player_t *player, pbl_t *game);
ennemy_t *create_ennemies(level_t *lvl, int nm, int x_spawn, int y_spawn);

void mode(pbl_t *game, window_t *win);

/*MAP*/
sfSprite **create_chest(char *path);
sfSprite **create_map(char *path);
sfSprite **create_teleport(char *path);
void draw_ground(window_t *win, pbl_t *game, level_t *lvl);

/*AUDIO*/
sound_t *init_audio(void);
sfSound **init_sound(void);
sfSound *create_sound(char *path);

#endif