/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void xor(global_t *g, int i, int w)
{
    int *len = coding_byte_len(dec_to_bin(int_from_grid(\
    g->grid, g->champ[i].pc[w] + 1, 1)), 0);
    int r1 = int_from_grid(g->grid, g->champ[i].pc[w] + 2, len[0]);
    int r2 = int_from_grid(g->grid, g->champ[i].pc[w] + 2 + len[0], len[1]);
    int r3 = int_from_grid(g->grid, g->champ[i].pc[w] + 2 + len[0] \
    + len[1], len[2]);
    int a = len[0] == 1 ? int_from_register(0, g->champ[i].registre[r1-1]) : r1;
    int b = len[1] == 1 ? int_from_register(0, g->champ[i].registre[r2-1]) : r2;
    int result = 0;

    if (len[2] != 1)
        g->champ[i].carry = 1;
    if (len[2] == 1) {
        result = a ^ b;
        for (int j = 0; j < REG_SIZE; j++)
            g->champ[i].registre[r3-1][j] = \
            (result >> ((REG_SIZE - j - 1) * 8)) & 0xFF;
        g->champ[i].carry = 0;
    }
    g->champ[i].pc[w] += 2 + len[0] + len[1] + len[2] + len[3];
}