/*
** EPITECH PROJECT, 2024
** B-CPE-110-MLN-1-1-organized-flavien.latrasse-chevalier
** File description:
** my_strchr.c
*/
#include <stdio.h>
#include <string.h>

char *my_strchr(const char *s, int c)
{
    while (*s) {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }
    if (c == '\0') {
        return (char *)s;
    }
    return NULL;
}
