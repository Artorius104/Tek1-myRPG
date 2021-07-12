/*
** EPITECH PROJECT, 2020
** get_nbr
** File description:
** get_nbr
*/

int get_start(char const *str)
{
    int i = 0;

    while (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
        i++;
    return i;
}

int my_getnbr(char const *str)
{
    int n = 0;
    int k = 0;
    int i = get_start(str);

    if (str[i] == '-') {
        k = 1;
        i++;
    }
    while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0') {
        n = n + (str[i] - '0');
        n *= 10;
        i++;
    }
    n /= 10;
    if (k == 1)
        n *= -1;
    return (n);
}
