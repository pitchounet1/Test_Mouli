/*
** EPITECH PROJECT, 2024
** B-CPE-110-MLN-1-1-organized-flavien.latrasse-chevalier
** File description:
** my_strlen.c
*/
#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
