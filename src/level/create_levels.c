/*
** EPITECH PROJECT, 2021
** create_level
** File description:
** create_level
*/

#include "rpg.h"

static int *take_size(char *buffer)
{
    int *pos = malloc(sizeof(int) * 2);

    buffer[my_strlen(buffer) - 1] = '\0';
    for (int k = 0; buffer[k] != '\0'; ++k)
        if (buffer[k] == '*') {
            pos[0] = my_getnbr(&buffer[k + 1]);
            buffer[k] = '\0';
            pos[1] = my_getnbr(buffer);
        }
    return pos;
}

static int place_map(char **map, char *buffer, int i, int pos)
{
    for (int j = 0; buffer[j] != '\0'; ++j) {
        if (buffer[j] == '\n')
            break;
        else
            map[i][j] = buffer[j];
    }
    map[i][pos] = '\0';
    return (i + 1);
}

static char **createmapfromfile(char *path)
{
    size_t len;
    FILE *fd = fopen(path, "r");
    char *buf = NULL;
    int *pos = NULL;
    char **map = NULL;

    getline(&buf, &len, fd);
    pos = take_size(buf);
    map = malloc(sizeof(char *) * (pos[0] + 1));
    for (int i = 0; i < pos[0]; ++i)
        map[i] = malloc(sizeof(char) * (pos[1] + 1));
    for (int k = 0, i = 0; k < pos[0]; ++k) {
        getline(&buf, &len, fd);
        i = place_map(map, buf, i, pos[1]);
    }
    map[pos[0]] = NULL;
    free(buf);
    free(pos);
    fclose(fd);
    return (map);
}

static level_t *map_info(level_t *lvl, char *path, int i)
{
    lvl->maps[i] = createmapfromfile(path);
    for (int line = 0; lvl->maps[i][line] != NULL; ++line)
        for (int y = 0; lvl->maps[i][line][y] != '\0'; ++y) {
            if (lvl->maps[i][line][y] == '3') {
                lvl->spawns[i].x = (float) (y * -96 + 943);
                lvl->spawns[i].y = (float) (line * -96 + 480);
            } else if (lvl->maps[i][line][y] == '0') {
                lvl->warps[i].x = (float) (y * -96);
                lvl->warps[i].y = (float) (line * -96);
            }
        }
    return lvl;
}

level_t *create_level(void)
{
    level_t *lvl = create_level_memory();

    lvl = map_info(lvl, "src/maps/level_start.txt", 0);
    lvl = map_info(lvl, "src/maps/level1.txt", 1);
    lvl = map_info(lvl, "src/maps/level2.txt", 2);
    lvl = map_info(lvl, "src/maps/level3.txt", 3);
    lvl = map_info(lvl, "src/maps/level4.txt", 4);
    lvl = map_info(lvl, "src/maps/level5.txt", 5);
    lvl = map_info(lvl, "src/maps/level6.txt", 6);
    lvl = map_info(lvl, "src/maps/level7.txt", 7);
    lvl = map_info(lvl, "src/maps/level8.txt", 8);
    lvl = map_info(lvl, "src/maps/level9.txt", 9);
    lvl = map_info(lvl, "src/maps/level10.txt", 10);
    lvl->ennemy = create_all_ennemies(lvl);
    lvl->chests = create_all_chests(lvl);
    return lvl;
}