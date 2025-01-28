/*
** EPITECH PROJECT, 2024
** organized
** File description:
** my_my_my_my_putnbr.c
*/
#include "my.h"

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return (0);
}
