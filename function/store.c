/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void store(global_t *g, int i, int w)
{
    int *len = coding_byte_len(dec_to_bin(int_from_grid(\
    g->grid, g->champ[i].pc[w] + 1, 1)), 0);
    int r1 = int_from_grid(g->grid, g->champ[i].pc[w] + 2, len[0]);
    int param = int_from_grid(g->grid, g->champ[i].pc[w] + 2 + len[0], \
    len[1]);

    if (param == 0)
        param = 256;
    if (len[1] != 1)
        for (int j = 0; j < REG_SIZE; j++) {
            g->grid[((g->champ[i].pc[w] + mod(param, IDX_MOD)) + j) % MEM_SIZE] = \
            g->champ[i].registre[r1-1][j];
            g->color[((g->champ[i].pc[w] + mod(param, IDX_MOD)) + j) % MEM_SIZE] = \
            g->champ[i].color;
        }
    if (len[1] == 1) {
        for (int j = 0; j < REG_SIZE; j++)
            g->champ[i].registre[param][j] = g->champ[i].registre[r1-1][j];
    }
    g->champ[i].pc[w] += 2 + len[0] + len[1] + len[2] + len[3];
}