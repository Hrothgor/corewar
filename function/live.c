/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void live(global_t *g, int i, int w)
{
    int number = int_from_grid(g->grid, g->champ[i].pc[w] + 1, DIR_SIZE);
    static int nb = NBR_LIVE;

    for (int j = 0; j < g->nb_champ; j++) {
        if (g->champ[j].nb == number) {
            g->champ[j].alive = g->cycle;
            printf("The player %i(%s) is alive.\n", \
            g->champ[j].nb, g->champ[j].header.prog_name);
        }
    }
    g->champ[i].pc[w] += 1 + DIR_SIZE;
    nb -= 1;
    if (nb == 0) {
        nb = NBR_LIVE;
        g->cycletd -= CYCLE_DELTA;
    }
}