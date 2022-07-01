#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "alloc_utils.h"

void initialize_arena(arena_t **arena, int N)
{
    *arena = (arena_t *)malloc(sizeof(**arena));
    DIE((*arena), "malloc() failed\n");

    (*arena)->byte_string = calloc(N, sizeof(char));
    DIE(!((*arena)->byte_string), "calloc() failed\n");

    (*arena)->size = N;
}

void finalize(arena_t *arena)
{
    free(arena->byte_string);
    free(arena);
}

void dump(arena_t *arena)
{
    for (int i = 0; i < arena->size; i += 16) {
        printf("%08X\t", i);
        for (int j = 0; j < 16 && i + j < arena->size; ++j) {
            char ch = *((char *)(arena->byte_string + i + j));

            if (j == 7)
                printf("%02X  ", ch);
            else
                printf("%02X ", ch);
        }

        printf("\n");
    }

    printf("%08X\n", arena->size);
}