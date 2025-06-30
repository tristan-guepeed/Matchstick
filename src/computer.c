#include "matchstick.h"
#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char **computer(char **map, char **argv)
{
    int count = 0;

    for (int i = 1; map[i] != map[my_getnbr(argv[1]) + 1]; i++) {
        for (int j = 1; map[i][j] != '*'; j++) {
            count = count + add_stick(map, i, j);
        }
        if (count != 1 && count != 0) {
            map = play_comp(map, argv, i, count);
            return (map);
        }
        count = 0;
    }
    last_stick(map);
    return (map);
}

char **last_stick(char **map)
{
    for (int i = 1; map[i] != NULL; i++) {
        for (int j = 1; map[i][j] != '\0'; j++) {
            if (map[i][j] == '|') {
                map[i][j] = ' ';
                my_putstr("AI removed 1 match(es) from line ");
                my_put_nbr(i);
                my_putchar('\n');
                return (map);
            }
        }
    }
    return (map);
}

int add_stick(char **map, int i, int j)
{
    int count = 0;

    if (map[i][j] == '|')
        count = count + 1;

    return (count);
}

char **play_comp(char **map, char **argv, int i, int count)
{
    int j = my_strlen(map[i]);
    int memory;

    if (count > my_getnbr(argv[2]))
        count = my_getnbr(argv[2]);
    else if (count < my_getnbr(argv[2]))
        count = count - 1;
    else
        count = count - 1;
    memory = count;
    while (count != 0) {
        if (map[i][j] == '|') {
            map[i][j] = ' ';
            count = count - 1;
        }
        j = j - 1;
    }
    display_ai(memory, i);
    return (map);
}

void display_ai(int memory, int i)
{
    my_putstr("AI removed ");
    my_put_nbr(memory);
    my_putstr(" match(es) from line ");
    my_put_nbr(i);
    my_putchar('\n');
}