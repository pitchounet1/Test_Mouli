/*
** EPITECH PROJECT, 2024
** B-CPE-110-MLN-1-1-organized-flavien.latrasse-chevalier
** File description:
** my_strtok.c
*/

#include <string.h>
#include "my.h"

char *my_strtok(char *str, const char *delim)
{
    static char *saved_str = NULL;
    char *token_start;

    if (str != NULL)
        saved_str = str;
    if (saved_str == NULL)
        return NULL;
    while (*saved_str != '\0' && my_strchr(delim, *saved_str) != NULL)
        saved_str++;
    if (*saved_str == '\0')
        return NULL;
    token_start = saved_str;
    while (*saved_str != '\0' && my_strchr(delim, *saved_str) == NULL)
        saved_str++;
    if (*saved_str != '\0') {
        *saved_str = '\0';
        saved_str++;
    }
    return token_start;
}
