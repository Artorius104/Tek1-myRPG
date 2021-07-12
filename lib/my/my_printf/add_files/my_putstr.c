/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

#include "../my_printf.h"

void my_putstr_p(char const *str)
{
    for (int x = 0; str[x] != '\0'; x++)
        my_putchar_p(str[x]);
}

void my_putstr_octal_p(char const *str)
{
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] < 32 || str[x] > 127)
            print_octal_s(str[x]);
        else
            my_putchar_p(str[x]);
    }
}
