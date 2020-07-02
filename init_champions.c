/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

champion_t fill_champions(champion_t ret, char *path)
{
    int fd;

    if ((fd = open(path, O_RDONLY)) == -1)
        exit(84);
    if (read(fd, &ret.header, sizeof(header_t)) == -1)
        exit(84);
    ret.header.magic = SWAP_UINT32(ret.header.magic);
    ret.header.prog_size = SWAP_UINT32(ret.header.prog_size);
    ret.carry = 0;
    for (int i = 0; i < REG_NUMBER; i++)
        for (int j = 0; j < REG_SIZE; j++)
            ret.registre[i][j] = 0;
    ret.registre[0][REG_SIZE-1] = ret.nb;
    ret.code = malloc(sizeof(char) * ret.header.prog_size);
    my_memset(ret.code, 0, ret.header.prog_size);
    read(fd, ret.code, ret.header.prog_size);
    close(fd);
    ret.alive = 0;
    return (ret);
}

int arg_ischampion(char *path)
{
    int len = my_strlen(path);

    if (path[len-1] == 'r' && path[len-2] == 'o' \
    && path[len-3] == 'c' && path[len-4] == '.')
        return (1);
    return (0);
}

int calc_nbchampion(int ac, char **av)
{
    int ret = 0;

    for (int i = 0; i < ac; i++)
        if (arg_ischampion(av[i]))
            ret += 1;
    return (ret);
}

champion_t parse_arg_champions(champion_t ret, char **av, int ac, int *i)
{
    int atm = *i + 1;

    for (int j = atm; j < atm + 4; j++) {
        if (j >= ac || arg_ischampion(av[j]))
            return (ret);
        if (av[j][0] == '-' && av[j][1] == 'n') {
            ret.nb = my_atoi(av[j+1]);
            *i += 2;
        }
        if (av[j][0] == '-' && av[j][1] == 'a') {
            ret.adress = my_atoi(av[j+1]) % MEM_SIZE;
            *i += 2;
        }
    }
    return (ret);
}

void init_champions(global_t *g, char **av, int ac)
{
    int ind = 0;
    int atm = 0;

    g->champ = malloc(sizeof(champion_t) * g->nb_champ);
    for (int i = 0; i < ac; i++) {
        if (arg_ischampion(av[i])) {
            atm = i;
            g->champ[ind].nb = ind+1;
            g->champ[ind].adress = (MEM_SIZE / g->nb_champ * ind);
            g->champ[ind] = parse_arg_champions(g->champ[ind], av, ac, &i);
            g->champ[ind] = fill_champions(g->champ[ind], av[atm]);
            g->champ[ind].pc = malloc(sizeof(int));
            g->champ[ind].cd = malloc(sizeof(int));
            g->champ[ind].pc[0] = g->champ[ind].adress;
            g->champ[ind].cd[0] = 0;
            g->champ[ind].nb_pc = 1;
            g->champ[ind].color = 31 + ind;
            ind += 1;
        }
    }
}