#include "lib.h"
#include <unistd.h>
#include <stddef.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    i = my_strlen(str);
    write(1, str, i);
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        ++i;
    return (i);
}

int my_strlen_modif(char **str)
{
    int i = 0;

    while (str[i] != NULL)
        ++i;
    return (i);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] > '/' && str[i] < ':')
            k = (k + (str[i] - 48)) * 10;
        if (str[i] == '-')
            j = j + 1;
        if ((str[i] > '@' && str[i] < '[') || (str[i] > '`' && str[i] < '{')) {
            k = k / 10;
            if ((j % 2) != 0)
                k = k * (-1);
            return (k);
        }
    }
    k = k / 10;
    if ((j % 2) != 0)
        k = k * (-1);
    return (k);
}

int my_put_nbr(int nbr)
{
    int i;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
        my_put_nbr(nbr);
    }
    else if (nbr >= 0 && nbr < 10)
        my_putchar(nbr + 48);
    else {
        i = nbr % 10;
        nbr = nbr / 10;
        my_put_nbr(nbr);
        my_putchar(i + 48);
    }
    return (0);
}

size_t my_getnbr_modif(char const *str)
{
    int i = 0;
    int j = 0;
    size_t k = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] > '/' && str[i] < ':')
            k = (k + (str[i] - 48)) * 10;
        if (str[i] == '-')
            j = j + 1;
        if ((str[i] > '@' && str[i] < '[') || (str[i] > '`' && str[i] < '{')) {
            k = k / 10;
            if ((j % 2) != 0)
                k = k * (-1);
            return (k);
        }
    }
    k = k / 10;
    if ((j % 2) != 0)
        k = k * (-1);
    return (k);
}