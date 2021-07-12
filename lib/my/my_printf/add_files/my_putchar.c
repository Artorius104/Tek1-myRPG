/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** my_putchar
*/

#include "../my_printf.h"

void my_putchar_p(char c)
{
    write(1, &c, 1);
}
