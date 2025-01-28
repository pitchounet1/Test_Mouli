/*
** EPITECH PROJECT, 2024
** my_put_hexa
** File description:
** hexa
*/

#include "my.h"
#include <unistd.h>

void my_put_hexa(int dec)
{
    int i = 1;
    int j = 0;
    int temp = 0;
    char hexa[100];

    while (dec != 0) {
        temp = dec % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        hexa[i] = temp;
        i++;
        dec = dec / 16;
    }
    for (j = i - 1; j > 0; j--)
        my_putchar(hexa[j]);
    return;
}
