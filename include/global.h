/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include "struct.h"

#define SWAP_UINT32(x) ((x >> 24) & 0xff) | (( x << 8) & 0xff0000) | ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)
