#include "matchstick.h"
#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int matchstick(char **argv)
{
    int z = 0;
    int y = 0;
    char **map = create_map(argv);

    map = init_map(map);
    while (z == 0) {
        player_turn(map, argv, &z);
        if (z == 2)
            return(y);
        re_check_map(map, &y, &z);
        if (y == 2) {
            free(map);
            return (y);
        }
        computer_turn(map, argv, &y, &z);
    }
    free(map);
    return (y);
}

char **computer_turn(char **map, char **argv, int *y, int *z)
{
    display_map(map);
    my_putstr("\nAI's turn...\n");    
    map = computer(map, argv);
    check_map(map, y, z);

    return (map);
}

char **player_turn(char **map, char **argv, int *z)
{
    display_map(map);
    my_putchar('\n');
    my_putstr("Your turn:\n");
    map = player(map, argv, z);

    return (map);
}

char **modif_map(int line, int match, char **map)
{
    int j = my_strlen(map[line]);

    while (match >= 1) {
        if (map[line][j] == '|') {
            map[line][j] = ' ';
            match = match - 1;
        }
        j = j - 1;
    }
    return (map);
}

char **create_map(char **argv)
{
    int i = 0;
    int j = 0;
    int k = lenght_line(argv);
    char **map = malloc(sizeof(char *) * (my_getnbr(argv[1]) + 2));

    while (i != my_getnbr(argv[1]) + 2) {
        map[i] = malloc(sizeof(char) * k + 1);
        while (j != k) {
            map[i][j] = '.';
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
    map[i] = NULL;
    return (map);
}