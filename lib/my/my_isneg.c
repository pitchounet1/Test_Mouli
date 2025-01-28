/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** write a function
*/
#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('-');
    } else if (n >= 0) {
        my_putchar('+');
    }
    return (0);
}
