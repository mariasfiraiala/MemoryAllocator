CC=gcc
CFLAGS=-I -g -Wall -Wextra -std=c99
DEPS=allocator.c

OBJ := alloc_utils.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

allocator: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o allocator