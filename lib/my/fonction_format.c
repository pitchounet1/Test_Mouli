/*
** EPITECH PROJECT, 2024
** fontions format
** File description:
** fonction format
*/
#include "my.h"
#include <stdarg.h>

void decimal(va_list args)
{
    my_put_nbr(va_arg(args, int));
    return;
}

void entier(va_list args)
{
    my_put_nbr(va_arg(args, int));
    return;
}

void character(va_list args)
{
    my_putchar(va_arg(args, int));
    return;
}

void string(va_list args)
{
    my_putstr(va_arg(args, char *));
    return;
}

void hexadecimal(va_list args)
{
    my_put_hexa(va_arg(args, int));
}
