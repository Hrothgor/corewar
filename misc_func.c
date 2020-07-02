/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "function.h"

int int_from_grid(char *grid, int index, int size)
{
    int result = 0;

    if (index < 0)
        index = MEM_SIZE - index;
    for (int i = 0; i < size; i++){
        result = result << 8;
        if (i != 0 && grid[index % MEM_SIZE] < 0 \
        && grid[(index - i) % MEM_SIZE] == -1)
            return (grid[index % MEM_SIZE]);
        result += grid[index % MEM_SIZE];
        index++;
    }
    return ((unsigned char) result);
}

int int_from_register(int index, char *registre)
{
    int result = 0;

    if (index < 0)
        index = MEM_SIZE - index;
    for (int i = 0; i < REG_SIZE; i++){
        result = result << 8;
        if (i != 0 && registre[index % MEM_SIZE] < 0 \
        && registre[(index - i) % MEM_SIZE] == -1)
            return (registre[index % MEM_SIZE]);
        result += registre[index % MEM_SIZE];
        index++;
    }
    return ((unsigned char) result);
}

char *dec_to_bin(int nb)
{
    char *bin = malloc(sizeof(char) * 8);

    my_memset(bin, '0', 8);
    for (int i = 0; i < 8; i++) {
        bin[7 - i] = nb % 2 + '0';
        nb /= 2;
    }
    return (bin);
}

int *coding_byte_len(char *bin, int exept)
{
    int *ret = malloc(sizeof(int) * 4);

    for (int i = 0; i < 8; i += 2) {
        if (bin[i] == '0' && bin[i+1] == '0')
            ret[i/2] = 0;
        if (bin[i] == '0' && bin[i+1] == '1')
            ret[i/2] = 1;
        if (bin[i] == '1' && bin[i+1] == '0')
            ret[i/2] = exept == 1 ? IND_SIZE : DIR_SIZE;
        if (bin[i] == '1' && bin[i+1] == '1')
            ret[i/2] = IND_SIZE;
    }
    return (ret);
}

int mod(int nb, int mod)
{
    if (nb < 0) {
        nb *= -1;
        nb = nb % mod;
        return (-nb);
    }
    return (nb % mod);
}