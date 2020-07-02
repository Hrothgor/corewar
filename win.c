/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void check_win(global_t *g)
{
    for (int i = 0; i < g->nb_champ; i++) {
        if (g->cycle - g->champ[i].alive > g->cycletd)
            g->alive = i;
    }
}