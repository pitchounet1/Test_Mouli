/*
** EPITECH PROJECT, 2024
** my_put_g
** File description:
** my_put_g
*/
#include "my.h"

void put_float_digits(double n, int count_int, int count_int_part)
{
    int k = count_int - count_int_part;
    float float_part;

    k = count_int - count_int_part;
    float_part = (n - (int)n);
    for (int i = 0; i < k + 1; i++) {
        float_part *= 10;
    }
    my_unsigned_integer((int)n);
    if (float_part != 0) {
        my_putchar('.');
        my_unsigned_integer(float_part);
    }
}

void pointg(double n)
{
    long int nb = n * 10000;
    int count_int = 0;
    int count_int_part = 0;

    for (int i = 10; (int)n > i; i *= 10) {
        count_int_part++;
    }
    while (nb % 10 == 0 && nb != 0) {
        nb /= 10;
    }
    for (int i = 10; nb > i; i *= 10) {
        count_int++;
    }
    if (count_int_part > 6) {
        my_put_exposant(n);
    } else {
        put_float_digits(n, count_int, count_int_part);
    }
    return;
}
