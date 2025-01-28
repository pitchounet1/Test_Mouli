/*
** EPITECH PROJECT, 2024
** putoctal
** File description:
** octal
*/
#include "my.h"
#include <unistd.h>

void my_put_octal(int dec)
{
    int i = 0;
    int j;
    int temp;
    char octal[100];

    while (dec != 0) {
        temp = dec % 8;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        octal[i] = temp;
        i++;
        dec = dec / 8;
    }
    for (j = i - 1; j >= 0; j--){
        my_putchar(octal[j]);
    }
    return;
}
