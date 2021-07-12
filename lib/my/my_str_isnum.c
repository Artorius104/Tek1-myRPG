/*
** EPITECH PROJECT, 2020
** CPool_Day06
** File description:
** my_str_isnum
*/

#include <stddef.h>

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return 0;
    if (str == NULL)
        return 1;

    return 1;
}
