/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** my_revstr
*/

#include "../my_printf.h"

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}

char *my_revstr(char *str)
{
    char rev;
    int i = 0;

    for (int j = (my_strlen(str) - 1); j > i; j--, i++) {
        rev = str[i];
        str[i] = str[j];
        str[j] = rev;
    }
    return str;
}
