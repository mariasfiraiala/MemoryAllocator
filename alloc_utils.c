#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "alloc_utils.h"

void initialize_arena(arena_t **arena, int N)
{
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

int alloc(arena_t *arena, int size)
{
    if (size > arena->size)
        return 0;

    int *start_index = ((int *)arena->byte_string);

    if (!(*start_index)) {
        *start_index = 4;
        *(start_index + 1) = 0;
        *(start_index + 2) = 0;
        *(start_index + 3) = 12 + size;

        return *start_index + 12;
    }
    else {

    }
}