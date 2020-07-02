/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

void init_arena(global_t *g)
{
    int index = 0;

    g->grid = malloc(sizeof(grid_t) * MEM_SIZE);
    g->color = malloc(sizeof(grid_t) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++) {
        g->grid[i] = 0;
        g->color[i] = 0;
    }
    for (int i = 0; i < g->nb_champ; i++) {
        index = g->champ[i].adress;
        for (int j = 0; j < g->champ[i].header.prog_size; j++) {
            if (g->grid[index % MEM_SIZE] != 0)
                exit(84);
            g->grid[index % MEM_SIZE] = g->champ[i].code[j];
            g->color[index % MEM_SIZE] = g->champ[i].color;
            index += 1;
        }
    }
}