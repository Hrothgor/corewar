/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

typedef void (*func)(global_t *, int, int);

const func tabl_func[] =
{
    &live,
    &load,
    &store,
    &addition,
    &soustraction,
    &and,
    &or,
    &xor,
    &zjmp,
    &load_index,
    &store_index,
    &ffork,
    &long_load,
    &long_load_index,
    &long_fork,
    &aff,
    NULL
};

void print_champions_info(global_t *g)
{
    for (int i = 0; i < g->nb_champ; i++) {
        printf("Champions %i:\n", i+1);
        printf("\tname: %s\n", g->champ[i].header.prog_name);
        printf("\tcomment: %s\n", g->champ[i].header.comment);
        printf("\tmagic: %i\n", g->champ[i].header.magic);
        printf("\tsize: %i\n", g->champ[i].header.prog_size);
        printf("\tcarry: %i\n", g->champ[i].carry);
        printf("\tadress: %i\n", g->champ[i].adress);
        printf("\tregistre: ");
        for (int j = 0; j < REG_NUMBER; j++) {
            printf("|");
            for (int k = 0; k < REG_SIZE; k++)
                printf("%02hhx", g->champ[i].registre[j][k]);
            printf("|");
        }
        printf("\n\tcode: ");
        for (int j = 0; j < g->champ[i].header.prog_size; j++)
            printf("%02hhx ", g->champ[i].code[j]);
        printf("\n\n");
    }
}

void print_arena(global_t *g)
{
    for (int i = 0; i < 48; i++) {
        for (int j = 0; j < MEM_SIZE / 48; j++) {
            printf("\033[0;%im", g->color[MEM_SIZE / 48 * i + j]);
            for (int k = 0; k < g->nb_champ; k++)
                for (int w = 0; w < g->champ[k].nb_pc; w++)
                    if (MEM_SIZE / 48 * i + j == g->champ[k].pc[w])
                        printf("\033[5m");
            printf("%02hhx ", g->grid[MEM_SIZE / 48 * i + j]);
        }
        printf("\n");
        printf("\033[0m");
    }
}

void update_champ(global_t *g, int nb, int w)
{
    int instru = int_from_grid(g->grid, g->champ[nb].pc[w], 1) - 1;
    int check = 0;

    for (int i = 0; tabl_func[i] != NULL; i++) {
        if (i == instru) {
            if (g->champ[nb].cd[w] == 0)
                g->champ[nb].cd[w] = op_tab[i].nbr_cycles;
            g->champ[nb].cd[w] -= 1;
            if (g->champ[nb].cd[w] == 0)
                tabl_func[i](g, nb, w);
            check = 1;
        }
    }
    if (check == 0) {
        g->champ[nb].pc[w] += 1;
        g->champ[nb].cd[w] = 0;
    }
}

global_t *init_global(int ac, char **av)
{
    global_t *g = malloc(sizeof(global_t));

    g->alive = -1;
    g->cycle = 0;
    g->dump = 0;
    g->cycletd = CYCLE_TO_DIE;
    g->nb_champ = calc_nbchampion(ac, av);
    init_champions(g, av, ac);
    init_arena(g);
    if (av[1][0] == '-' && av[1][1] == 'd' && av[1][2] == 'u' \
    && av[1][3] == 'm' && av[1][4] == 'p')
        g->dump = 1;
    return (g);
}

int main(int ac, char **av)
{
    global_t *g = init_global(ac, av);

    //print_champions_info(g);
    while (g->alive == -1) {
        usleep(1000);
        for (int i = 0; i < g->nb_champ; i++)
            for (int w = 0; w < g->champ[i].nb_pc; w++) {
                update_champ(g, i, w);
                g->champ[i].pc[w] = g->champ[i].pc[w] % MEM_SIZE;
            }
        if (g->cycle % 50 == 0 && g->dump == 1) {
            printf("\e[1;1H\e[2J");
            printf("cycle: %i\n", g->cycle);
            print_arena(g);
        }
        check_win(g);
        g->cycle++;
    }
    printf("The player %i(%s) has won.\n", \
    g->alive, g->champ[g->alive-1].header.prog_name);
}
