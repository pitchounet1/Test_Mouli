/*
** EPITECH PROJECT, 2024
** puthexa
** File description:
** puthexa
*/
#include "my.h"
#include <stdint.h>

int my_put_uintptr(uintptr_t dec)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    char hexa[100];

    while (dec != 0) {
        temp = dec % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 87;
        }
        hexa[i] = temp;
        i++;
        dec = dec / 16;
    }
    for (j = i - 1; j >= 0; j--)
        my_putchar(hexa[j]);
    return (0);
}
