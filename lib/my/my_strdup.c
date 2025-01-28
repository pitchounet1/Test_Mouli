/*
** EPITECH PROJECT, 2024
** B-CPE-110-MLN-1-1-organized-flavien.latrasse-chevalier
** File description:
** my_strdup.c
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (new_str == NULL)
        return NULL;
    for (i = 0; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return new_str;
}
