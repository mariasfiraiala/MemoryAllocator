#ifndef ALLOC_UTILS_H__
#define ALLOC_UTILS_H__

typedef struct __attribute__((__packed__)) arena_t {
    int size;
    void *byte_string;
} arena_t;

#define DIE(assertion, call_description)                                       \
    do {                                                                       \
        if (assertion) {                                                       \
            fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);                 \
            perror(call_description);                                          \
            exit(errno);                                                       \
        }                                                                      \
    } while (0)

void initialize_arena(arena_t **arena, int N);

void finalize(arena_t *arena);

void dump(arena_t *arena);

int alloc(arena_t *arena, int size);

#endif // ALLOC_UTILS_H__