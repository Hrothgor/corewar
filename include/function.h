/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include "my.h"
#include "global.h"
#include "include.h"
#include "op.h"

//////// CHAMPION ////////

champion_t fill_champions(champion_t ret, char *path);
int arg_ischampion(char *path);
int calc_nbchampion(int ac, char **av);
champion_t parse_arg_champions(champion_t ret, char** av, int ac, int *i);
void init_champions(global_t *g, char **av, int ac);

//////// ARENA ////////

void init_arena(global_t *g);

//////// MISC FUNC ////////

int int_from_grid(char *grid, int index, int size);
int int_from_register(int index, char *registre);
char *dec_to_bin(int nb);
int *coding_byte_len(char *bin, int exept);
int mod(int nb, int mod);
void check_win(global_t *g);

//////// FUNCTION ////////

void live(global_t *g, int i, int w);
void load(global_t *g, int i, int w);
void store(global_t *g, int i, int w);
void addition(global_t *g, int i, int w);
void soustraction(global_t *g, int i, int w);
void and(global_t *g, int i, int w);
void or(global_t *g, int i, int w);
void xor(global_t *g, int i, int w);
void zjmp(global_t *g, int i, int w);
void load_index(global_t *g, int i, int w);
void store_index(global_t *g, int i, int w);
void ffork(global_t *g, int i, int w);
void long_load(global_t *g, int i, int w);
void long_load_index(global_t *g, int i, int w);
void long_fork(global_t *g, int i, int w);
void aff(global_t *g, int i, int w);