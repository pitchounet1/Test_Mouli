/*
** EPITECH PROJECT, 2024
** B-PSU-100-MLN-1-1-mysudo-flavien.latrasse-chevalier
** File description:
** my.h
*/

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <crypt.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>

#ifndef MY_H
    #define MY_H

    #define _GNU_SOURCE
    #define MAX_ATTEMPTS 3
    #define SUDOERS_PATH "/etc/sudoers"
    #define SHADOW_PATH "/etc/shadow"
    #define PASSWD_PATH "/etc/passwd"

typedef struct {
    char **av;
    char *target_user;
    gid_t target_gid;
} sudo_options_t;

typedef struct {
    char username[256];
    char stored_hash[256];
} user_info_t;

int check_user_in_sudoers(const char *username);
int find_user_in_sudoers(FILE *file, const char *username);
char *my_strtok(char *str, const char *delim);
int set_target_user_and_group(const char *target_user, uid_t *uid, gid_t *gid);
int validate_sudoers(const char *username);
int my_printf(char *format, ...);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_put_hexa(int dec);
void my_put_lower_hexa(int dec);
void my_put_octal(int n);
void my_put_float(double x);
void my_unsigned_integer(unsigned int a);
void my_put_exposant(double n);
void my_pointer(va_list args);
int my_put_uintptr(uintptr_t ptr);
void pointg(double n);
void decimal(va_list args);
void entier(va_list args);
void string(va_list args);
void character(va_list args);
void hexadecimal(va_list args);
void hexadecimal_lower(va_list args);
void octal(va_list args);
void flottant(va_list args);
void unsigned_integer(va_list args);
void exposant(va_list args);
void gpoint(va_list args);
int power(int nb, int p);
int my_isneg(int n);
char *my_strchr(const char *s, int c);
char *my_strtok(char *str, const char *delim);
char *my_strdup(char *str);
int my_strlen(char *str);
int my_atoi(char *str);
int my_putnbr(int nb);
void my_putchar(char c);
int my_putstr(const char *str);
int my_strcmp(char const *s1, char const *s2);

#endif /* !MY_H */
