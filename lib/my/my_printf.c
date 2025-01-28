/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** print
*/
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "my.h"

struct last_flags {
    void (*function)(va_list args);
    char last_flag;
};

const struct last_flags struct_flag[] = {
    {&decimal, 'd'},
    {&entier, 'i'},
    {&character, 'c'},
    {&string, 's'},
    {&hexadecimal, 'X'},
    {&hexadecimal_lower, 'x'},
    {&octal, 'o'},
    {&flottant, 'f'},
    {&unsigned_integer, 'u'},
    {&exposant, 'e'},
    {&my_pointer, 'p'},
    {&gpoint, 'g'},
    {NULL, '\0'}
};

int print_flag(va_list args, char *format, int j)
{
    if (format[j] == '%') {
        my_putchar('%');
        return (0);
    }
    for (int i = 0; struct_flag[i].last_flag != '\0'; i++) {
        if (struct_flag[i].last_flag == format[j]) {
            struct_flag[i].function(args);
            return (0);
        }
    }
    j--;
    my_putchar('%');
    j++;
    my_putchar(format[j]);
    return (0);
}

int my_printf(char *format, ...)
{
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            print_flag(args, format, i);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(args);
    return (0);
}
