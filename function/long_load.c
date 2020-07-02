/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void long_load(global_t *g, int i, int w)
{
    int *len = coding_byte_len(dec_to_bin(int_from_grid(\
    g->grid, g->champ[i].pc[w] + 1, 1)), 0);
    int size = int_from_grid(g->grid, g->champ[i].pc[w] + 2, len[0]);
    int r1 = int_from_grid(g->grid, g->champ[i].pc[w] + 2 + len[0], \
    len[1]);

    if (len[0] == 4) {
        for (int j = 0; j < REG_SIZE; j++)
            g->champ[i].registre[r1-1][j] = \
            g->grid[((g->champ[i].pc[w] + 2 + j) % MEM_SIZE)];
    } else {
        for (int j = 0; j < REG_SIZE; j++)
            g->champ[i].registre[r1-1][j] = \
            g->grid[((g->champ[i].pc[w] + size) + j) % MEM_SIZE];
    }
    g->champ[i].pc[w] += 2 + len[0] + len[1] + len[2] + len[3];
    g->champ[i].carry = size == 0 ? 1 : 0;
}