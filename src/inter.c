#include "matchstick.h"
#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void inter_one(char **map, char **argv, int *z)
{
    my_putstr("Error: this line is out of range\n");
    player(map, argv, z);
}

void inter_two(char **map, char **argv, int *z)
{
    error_match(argv);
    player(map, argv, z);
}

void invalid_input(char **map, char **argv, int *z)
{
    my_putstr("Error: invalid input (positive number expected)\n");
    player(map, argv, z);
}

void no_match(char **map, char **argv, int *z)
{
    my_putstr("Error: you have to remove at least one match\n");
    player(map, argv, z);
}

int check_error(char *map, char **argv, int *z, char *str, char **mapa)
{
    int count = 0;
    int i = 0;

    if (my_getnbr(str) == 0) {
        no_match(mapa, argv, z);
        return (543);
    }
    while (map[i] != '\0') {
        if (map[i] == '|')
            count = count + 1;
        i = i + 1;
    }
    if (count < my_getnbr(str) && my_getnbr(str) < my_getnbr(argv[2])) {
        my_putstr("Error: not enough matches on this line\n");
        player(mapa, argv, z);
        return (543);
    }
    return (0);
}