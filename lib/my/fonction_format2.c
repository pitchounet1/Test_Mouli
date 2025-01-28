/*
** EPITECH PROJECT, 2024
** fontion
** File description:
** fonction
*/
#include "my.h"

void octal(va_list args)
{
    my_put_octal(va_arg(args, int));
    return;
}

void hexadecimal_lower(va_list args)
{
    my_put_lower_hexa(va_arg(args, int));
    return;
}

void flottant(va_list args)
{
    my_put_float(va_arg(args, double));
    return;
}

void unsigned_integer(va_list args)
{
    my_unsigned_integer(va_arg(args, int));
    return;
}

void exposant(va_list args)
{
    my_put_exposant(va_arg(args, double));
}
