/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** do something
*/
#include "my.h"

int power(int nb, int p)
{
    int i = 1;

    if (nb == 0) {
        return (0);
    }
    if (p < 0) {
        return (0);
    }
    while (i < p) {
        nb = nb * nb;
        i++;
    }
    return (nb);
}
