/*
** EPITECH PROJECT, 2024
** organized
** File description:
** my_my_my_my_putstr.c
*/
#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
    return (0);
}
