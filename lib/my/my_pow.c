/*
** EPITECH PROJECT, 2020
** my_pow
** File description:
** my_pow
*/

int my_pow(int nb, int pow)
{
    int result = nb;

    if (pow == 1)
        return result;
    if (pow == 0)
        return 1;
    for (int i = 1; i < pow; i++)
        result *= nb;
    return result;
}
