/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include "include.h"
#include "op.h"

typedef struct champion {
    header_t header;
    int nb;
    int adress;
    char *code;
    int carry;
    int *pc;
    int *cd;
    int nb_pc;
    int color;
    int alive;
    char registre[REG_NUMBER][REG_SIZE];
} champion_t;

typedef struct grid {
    char c;
    int color;
} grid_t;

typedef struct global {
    champion_t *champ;
    int nb_champ;
    char *grid;
    int *color;
    int alive;
    int cycle;
    int cycletd;
    int dump;
} global_t;