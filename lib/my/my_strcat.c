/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_strcat.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);

    for (int j = 0; src[j] != '\0' ; i++, j++)
        dest[i] = src[j];
    dest[i] = '\0';

    return dest;
}

char *my_strcat_r(char *dest, char const *src)
{
    int len = my_strlen(dest) + my_strlen(src);
    char *str_tmp = malloc(sizeof(char) * len + 1);
    int i = 0;

    for (; dest[i] != '\0'; i++)
        str_tmp[i] = dest[i];
    for (int j = 0; src[j] != '\0' ; i++, j++)
        str_tmp[i] = src[j];
    str_tmp[i] = '\0';

    return str_tmp;
}
