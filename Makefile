# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Loader flags (ex. for math.h)
LDFLAGS = -lm

# Here you can add object files
OBJ = allocator.o

# Here is the name for executable
EXE = allocator

build: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXE) $(LDFLAGS)

run: build
	./$(EXE)

# How cool can be this Makefile? Can pack my homework.
# Hint: make sure you add all files in zip.
pack:
	zip -FSr project-skel.zip allocator.c Makefile README

.PHONY: clean
clean:
	rm -f *.o $(EXE) 