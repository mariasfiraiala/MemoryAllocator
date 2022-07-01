#ifndef ALLOC_UTILS_H__
#define ALLOC_UTILS_H__

typedef struct __attribute__((__packed__)) arena_t {
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

#endif // ALLOC_UTILS_H__