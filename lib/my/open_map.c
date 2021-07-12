/*
** EPITECH PROJECT, 2021
** openmap
** File description:
** openmap
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int *get_size(char *buffer)
{
    int *arr = malloc(sizeof(int) * 2);
    int t = 0, z = 0;

    for (int i = 0, a = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            z = a > z ? a : z;
            t++;
            a = 0;
        } else
            a++;
    }
    arr[0] = t;
    arr[1] = z;
    return arr;
}

char **buffer_to_char(char *buffer)
{
    char **map = NULL;
    int *arr = get_size(buffer);

    map = malloc(sizeof(char *) * arr[0]);
    for (int i = 0; i < arr[0]; i++)
        map[i] = (char *) malloc(sizeof(char) * arr[1]);
    for (int q = 0, k = 0, c = 0; buffer[q] != '\0'; q++) {
        if (buffer[q] == '\n') {
            map[k][c] = '\0';
            k++;
            c = 0;
        } else {
            map[k][c] = buffer[q];
            c++;
        }
    }
    map[arr[0]] = NULL;
    return (map);
}

char **open_map(char *pth)
{
    struct stat buf;
    size_t buffsize;
    stat(pth, &buf);
    char *str_tmp = malloc(sizeof(char) * buf.st_size);
    FILE *fd = fopen(pth, "r");
    char *buff = NULL;
    while (getline(&buff, &buffsize, fd) != -1)
        my_strcat(str_tmp, buff);
    str_tmp[buf.st_size - 1] = '\n';
    str_tmp[buf.st_size] = '\0';
    char **buffer = buffer_to_char(str_tmp);
    return buffer;
}