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