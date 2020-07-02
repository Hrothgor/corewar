/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void long_fork(global_t *g, int i, int w)
{
    int number = int_from_grid(g->grid, g->champ[i].pc[w] + 1, IND_SIZE);

    g->champ[i].nb_pc += 1;
    g->champ[i].pc = realloc(g->champ[i].pc, sizeof(int) * g->champ[i].nb_pc);
    g->champ[i].cd = realloc(g->champ[i].pc, sizeof(int) * g->champ[i].nb_pc);
    g->champ[i].pc[g->champ[i].nb_pc - 1] = g->champ[i].pc[w] + number;
    g->champ[i].cd[g->champ[i].nb_pc - 1] = 0;
    g->champ[i].pc[w] += 1 + IND_SIZE;
}