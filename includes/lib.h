#ifndef _LIB_H_
#define _LIB_H_

#include <stddef.h>

int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
int my_getnbr(char const *str);
int my_strlen_modif(char **str);
int my_put_nbr(int nbr);
size_t my_getnbr_modif(char const *str);

#endif // LIB_H_//