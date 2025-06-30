#include "matchstick.h"
#include "lib.h"
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        my_putstr("USAGE\n\t./matchstick [number of lines] [number of matches per turn]\n");
        my_putstr("DESCRIPTION\n\t[number of lines]\t\tis the number of lines in the matchstick game\n");
        my_putstr("\t[number of matches per turn]\tis the number of matches that can be removed per turn\n");
        return (0);
    }
    int i = 0;
    int a = my_getnbr(argv[1]);

    if (a > 99 || a < 1)
        return (84);
    if (argc != 3)
        return (84);
    i = matchstick(argv);

    return (i);
}