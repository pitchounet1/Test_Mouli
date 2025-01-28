/*
** EPITECH PROJECT, 2024
** exposant
** File description:
** exposant
*/
#include "my.h"

void my_put_exposant(double n)
{
    int i = 0;

    while ((int)n != 0) {
        n /= 10;
        i++;
    }
    while (n > 0 && n < 1) {
        n *= 10.0;
        i--;
    }
    my_put_float(n);
    my_putchar('e');
    if (i >= 0) {
        my_putchar('+');
    }
    my_put_nbr(0);
    my_put_nbr(i);
}
