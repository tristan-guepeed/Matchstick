#include "matchstick.h"
#include "lib.h"
#include <stddef.h>
#include <stdlib.h>

char **display_map(char **tab)
{
    int j = 0;

    while (tab[j] != NULL) {
        my_putstr(tab[j]);
        my_putchar('\n');
        j = j + 1;
    }
    return (tab);
}

int lenght_line(char **argv)
{
    int i = my_getnbr(argv[1]);
    int j = 1;
    int k = j + 2;

    while (j != i) {
        k = k + 2;
        j = j + 1;
    }
    return (k);
}

char **init_map(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        suite_init(map, i, j);
        i = i + 1;
        j = 0;
    }
    map = display_stick(map);
    return (map);
}

char **display_stick(char **map)
{
    int i = 0;
    int b = my_strlen(map[i]) - 1;
    int a = 1;
    int c = a;
    int k = my_strlen_modif(map) - 2;

    while (k != i) {
        while (a != b) {
            map[k][a] = '|';
            a = a + 1;
        }
        c = c + 1;
        a = c;
        b = b - 1;
        k = k - 1;
    }
    return (map);
}

char **suite_init(char **map, int i, int j)
{
    while (map[i][j] != '\0') {
        if (i == 0 || i == my_strlen_modif(map) - 1)
            map[i][j] = '*';
        else if (j == 0 || j == my_strlen(map[i]) - 1)
            map[i][j] = '*';
        else
            map[i][j] = ' ';
        j = j + 1;
    }
    return (map);
}