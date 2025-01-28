/*
** EPITECH PROJECT, 2024
** B-PSU-100-MLN-1-1-mysudo-flavien.latrasse-chevalier
** File description:
** main.c
*/
#include "my.h"

void description(void)
{
    fprintf(stderr, "usage: ./my_sudo -h\n");
    fprintf(stderr, "usage: ./my_sudo [-ugEs] [command [args ...]]\n");
}

static int open_shadow_file(FILE **shadow_file)
{
    *shadow_file = fopen(SHADOW_PATH, "r");
    if (!*shadow_file) {
        perror("Error opening shadow file");
        return 84;
    }
    return 0;
}

static int find_stored_hash(FILE *shadow_file,
    const char *username, char *stored_hash)
{
    char line[512];

    while (fgets(line, sizeof(line), shadow_file)) {
        if (strncmp(line, username, strlen(username)) == 0 &&
        line[strlen(username)] == ':') {
            strtok(line, ":");
            strcpy(stored_hash, strtok(NULL, ":"));
            return 0;
        }
    }
    fprintf(stderr, "User %s not found in shadow file.\n", username);
    return 84;
}

static int get_stored_hash(const char *username, char *stored_hash)
{
    FILE *shadow_file;

    if (open_shadow_file(&shadow_file) == 84) {
        return 84;
    }
    if (find_stored_hash(shadow_file, username, stored_hash) == 84) {
        fclose(shadow_file);
        return 84;
    }
    fclose(shadow_file);
    return 0;
}

static int authenticate_user(user_info_t *user_info)
{
    char *input_password = NULL;

    if (get_stored_hash(user_info->username, user_info->stored_hash) != 0) {
        return 84;
    }
    for (int attempts = 0; attempts < MAX_ATTEMPTS; attempts++) {
        printf("[my_sudo] password for %s: ", user_info->username);
        input_password = getpass("");
        if (strcmp(crypt(input_password, user_info->stored_hash),
        user_info->stored_hash) == 0) {
            printf("Authentication successful. Failed attempts: %d\n",
            attempts);
            return 0;
        }
        fprintf(stderr, "Incorrect password.\n");
    }
    return 84;
}

static int find_username_in_passwd(FILE *passwd_file, uid_t uid,
    char *username, size_t size)
{
    char line[256];
    char *user;
    uid_t file_uid;

    while (fgets(line, sizeof(line), passwd_file)) {
        user = strtok(line, ":");
        strtok(NULL, ":");
        file_uid = (uid_t)atoi(strtok(NULL, ":"));
        if (file_uid == uid) {
            strncpy(username, user, size);
            return 0;
        }
    }
    return 84;
}

int get_current_username(char *username, size_t size)
{
    FILE *passwd_file = fopen(PASSWD_PATH, "r");
    uid_t uid = getuid();

    if (!passwd_file) {
        perror("Error opening /etc/passwd");
        return 84;
    }
    if (find_username_in_passwd(passwd_file, uid, username, size) == 84) {
        fclose(passwd_file);
        fprintf(stderr, "Current user not found in /etc/passwd.\n");
        return 84;
    }
    fclose(passwd_file);
    return 0;
}

int execute_command(uid_t uid, gid_t gid, char **av)
{
    if (setgid(gid) != 0 || setuid(uid) != 0) {
        perror("Failed to set user/group ID");
        return 84;
    }
    execvp(av[1], &av[1]);
    perror("Failed to execute command");
    return 84;
}

int run_sudo(sudo_options_t *options)
{
    user_info_t user_info;
    uid_t target_uid;

    if (get_current_username(user_info.username,
    sizeof(user_info.username)) != 0)
        return 84;
    if (check_user_in_sudoers(user_info.username) != 0)
        return 84;
    if (authenticate_user(&user_info) != 0)
        return 84;
    target_uid =
    options->target_user ? (uid_t)atoi(options->target_user) : getuid();
    if (options->target_gid == (gid_t)-1)
        options->target_gid = getgid();
    if (execute_command(target_uid, options->target_gid, options->av))
        return 84;
    return 0;
}

int main(int argc, char **argv)
{
    sudo_options_t *options = malloc(sizeof(sudo_options_t));

    if (!options) {
        perror("Failed to allocate memory");
        return 84;
    }
    options->target_gid = (gid_t)-1;
    options->av = argv;
    options->target_user = NULL;
    if (argc < 2 || strcmp(argv[1], "-h") == 0) {
        description();
        return 0;
    }
    if (run_sudo(options) == 84) {
        return 84;
    }
    return 0;
}
