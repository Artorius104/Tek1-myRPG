/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *dest, char const *src, int n_1, int n_2)
{
    int t = 0;

    for (int i = n_1; i < (n_2 + n_1); i++, t++)
        dest[t] = src[i];
    dest[t] = '\0';

    return dest;
}
