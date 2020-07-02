/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void store_index(global_t *g, int i, int w)
{
    int *len = coding_byte_len(dec_to_bin(int_from_grid(\
    g->grid, g->champ[i].pc[w] + 1, 1)), 1);
    int r1 = int_from_grid(g->grid, g->champ[i].pc[w] + 2, len[0]);
    int r2 = int_from_grid(g->grid, g->champ[i].pc[w] + 2 + len[0], len[1]);
    int r3 = int_from_grid(g->grid, g->champ[i].pc[w] + 2 + len[0] \
    + len[1], len[2]);
    int a = len[1] == 1 ? int_from_register(0, g->champ[i].registre[r2-1]) : r2;
    int b = len[2] == 1 ? int_from_register(0, g->champ[i].registre[r3-1]) : r3;

    for (int j = 0; j < REG_SIZE; j++) {
        g->grid[(g->champ[i].pc[w] + mod((a + b), IDX_MOD) + j) % MEM_SIZE] = \
        g->champ[i].registre[r1-1][j];
        g->color[(g->champ[i].pc[w] + mod((a + b), IDX_MOD) + j) % MEM_SIZE] = \
        g->champ[i].color;
    }
    g->champ[i].pc[w] += 2 + len[0] + len[1] + len[2] + len[3];
}