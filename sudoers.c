/*
** EPITECH PROJECT, 2024
** B-PSU-100-MLN-1-1-mysudo-flavien.latrasse-chevalier
** File description:
** sudoers.c
*/

#include "my.h"

int check_user_in_sudoers(const char *username)
{
    FILE *file = fopen(SUDOERS_PATH, "r");

    if (!file) {
        perror("Error opening sudoers file");
        return 84;
    }
    if (find_user_in_sudoers(file, username) == 84) {
        fclose(file);
        return 84;
    }
    fclose(file);
    return 0;
}

int find_user_in_sudoers(FILE *file, const char *username)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, username) == 0 || line[0] == '%') {
            free(line);
            return 0;
        }
    }
    free(line);
    fprintf(stderr, "%s is not in the sudoers file.\n", username);
    return 84;
}
