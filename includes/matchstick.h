#ifndef _MATCHSTICK_H_
#define _MATCHSTICK_H_

#include <stddef.h>

int main(int argc, char **argv);
int matchstick(char **argv);
int lenght_line(char **argv);
char **create_map(char **argv);
char **display_map(char **tab);
char **init_map(char **map);
char **suite_init(char **map, int i, int j);
char **display_stick(char **map);
char **modif_map(int line, int match, char **map);
char **player(char **map, char **argv, int *z);
void next_turn(int line, int match);
size_t check_match(char **map, char **argv, int *z, int line);
size_t check_line(char **map, char **argv, int *z);
void error_match(char **argv);
int check_map(char **map, int *y, int *z);
int count_stick(char **argv, int i, int *j);
void inter_two(char **map, char **argv, int *z);
void inter_one(char **map, char **argv, int *z);
void invalid_input(char **map, char **argv, int *z);
void no_match(char **map, char **argv, int *z);
int check_error(char *map, char **argv, int *z, char *str, char **mapa);
char **play_comp(char **map, char **argv, int i, int count);
char **computer(char **map, char **argv);
int re_check_map(char **map, int *y, int *z);
void display_ai(int memory, int i);
int add_stick(char **map, int i, int j);
char **last_stick(char **map);
char **player_turn(char **map, char **argv, int *z);
char **computer_turn(char **map, char **argv, int *y, int *z);
int check_str(char *str);

#endif // MATCHSTICK_H_//