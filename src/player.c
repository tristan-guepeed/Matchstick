#include "matchstick.h"
#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char **player(char **map, char **argv, int *z)
{
    size_t line;
    size_t match;

    line = check_line(map, argv, z);
    if (line == 543)
        return (map);
    if (line == 0 || line > my_getnbr_modif(argv[1]) || line > 214783647) {
        inter_one(map, argv, z);
        return (map);
    }
    match = check_match(map, argv, z, line);
    if (match == 543)
        return (map);
    if (match > my_getnbr_modif(argv[2])) {
        inter_two(map, argv, z);
        return (map);
    }
    map = modif_map(line, match, map);
    next_turn(line, match);
    return (map);
}

size_t check_line(char **map, char **argv, int *z)
{
    size_t a = 0;
    char *str = NULL;
    size_t line;
    int v = 0;

    my_putstr("Line: ");
    if (getline(&str, &a, stdin) == -1) {
        *z = 2;
        return (543);
    }
    while (v == 0) {
        if (check_str(str) == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            player(map, argv, z);
            return (543);
        }
        v = v + 1;
    }
    line = my_getnbr_modif(str);
    return (line);
}

size_t check_match(char **map, char **argv, int *z, int line)
{
    size_t a = 0;
    char *str = NULL;
    int v = 0;

    my_putstr("Matches: ");
    if (getline(&str, &a, stdin) == -1) {
        *z = 2;
        return (543);
    }
    while (v == 0) {
        if (check_str(str) == 1) {
            invalid_input(map, argv, z);
            return (543);
        }
        v = v + 1;
    }
    if (check_error(map[line], argv, z, str, map) == 543) {
        return (543);
    }
    return (my_getnbr_modif(str));
}

void next_turn(int line, int match)
{
    my_putstr("Player removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

void error_match(char **argv)
{
    my_putstr("Error: you cannot remove more than ");
    my_put_nbr(my_getnbr(argv[2]));
    my_putstr(" matches per turn\n");   
}

int check_map(char **map, int *y, int *z)
{
    int i = 1;
    int j = 1;
    int k = 0;

    while (map[i] != NULL) {
        while (map[i][j] != '*') {
            k = k + count_stick(map, i, &j);
        }
        i = i + 1;
        j = 1;
    }
    if (k == 0) {
        display_map(map);
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        *y = 1;
        *z = 1;
        return (1);
    }
    return (0);
}

int re_check_map(char **map, int *y, int *z)
{
    int i = 1;
    int j = 1;
    int k = 0;

    while (map[i] != NULL) {
        while (map[i][j] != '*') {
            k = k + count_stick(map, i, &j);
        }
        i = i + 1;
        j = 1;
    }
    if (k == 0) {
        display_map(map);
        my_putstr("You lost, too bad...\n");
        *y = 2;
        *z = 1;
        return (1);
    }
    return (0);
}

int count_stick(char **map, int i, int *j)
{
    int k = 0;

    if (map[i][*j] == '|')
        k = k + 1;
    *j = *j + 1;

    return (k);
}

int check_str(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i = i + 1;
    }
    return (0);
}