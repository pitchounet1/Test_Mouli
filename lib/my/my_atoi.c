/*
** EPITECH PROJECT, 2024
** organized
** File description:
** my_atoi.c
*/

#include <stdio.h>
#include "my.h"

int my_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
    || str[i] == '\v' || str[i] == '\f')
        i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * sign);
}
