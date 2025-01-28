/*
** EPITECH PROJECT, 2024
** my put float
** File description:
** print a float
*/
#include "my.h"

void my_put_float(double x)
{
    int intpart = (int)x;
    int floatpart = (x - intpart) * 1000000;

    if (floatpart < 0) {
        floatpart *= -1;
    }
    my_put_nbr(intpart);
    my_putchar('.');
    my_put_nbr(floatpart);
}
