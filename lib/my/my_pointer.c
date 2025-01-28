/*
** EPITECH PROJECT, 2024
** pointer
** File description:
** p
*/

#include "my.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

void my_pointer(va_list args)
{
    void *adresse = va_arg(args, void *);
    uintptr_t ptr = (uintptr_t)adresse;

    my_putstr("0x");
    my_put_uintptr(ptr);
    return;
}
