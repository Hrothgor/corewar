/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void zjmp(global_t *g, int i, int w)
{
    int number = int_from_grid(g->grid, g->champ[i].pc[w] + 1, IND_SIZE);

    if (g->champ[i].carry == 1) {
        g->champ[i].pc[w] = (g->champ[i].pc[w] + mod(number, IDX_MOD)) % MEM_SIZE;
    } else {
        g->champ[i].pc[w] += 1 + IND_SIZE;
    }
}