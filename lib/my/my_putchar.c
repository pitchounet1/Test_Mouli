/*
** EPITECH PROJECT, 2024
** my_my_putchar
** File description:
** do something
*/
#include <unistd.h>
#include <stdio.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
