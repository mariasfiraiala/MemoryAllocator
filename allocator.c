// Copyright 2022 Maria Sfiraiala (maria.sfiraiala@stud.acs.upb.ro)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "alloc_utils.h"

#define MAX_LINE_LEN 1000
#define MAX_CMD_ARGS 10

// read a new command from stdin
int cmd_read(int *args_count, char *args[MAX_CMD_ARGS])
{
    char line[MAX_LINE_LEN + 1]; //  buffer for a line

    // try to read a new command (a new line)
    if (!fgets(line, MAX_LINE_LEN, stdin)) {
        return 0; // fail
    }

    // delete extra '\n'
    int len = strlen(line);
    if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    // split string in tokens ("words")
    const char *delimiters = " ";       // delimiters
    int count = 0;                      // number of tokens
    char *token = strtok(line, delimiters); // get first token

    while (token != NULL) {
        // save current token
        len = strlen(token) + 1; // +1 because I need to store '\0'
        args[count] = (char *) malloc(len * sizeof(char));
        strcpy(args[count], token);

        // get next token
        token = strtok(NULL, delimiters);
        ++count;
    }

    *args_count = count; // save arguments count

    return 1;            // success
}

// execute a command
void cmd_execute(int args_count, char *args[MAX_CMD_ARGS], arena_t *arena)
{
    char *cmd = args[0];

    if (!strcmp(cmd, "INITIALIZE")) {
        int N = atoi(args[1]);
        initialize_arena(&arena, N);
    } else if (!strcmp(cmd, "FINALIZE")) {
        finalize(arena);
    } else if (!strcmp(cmd, "DUMP")) {
        dump(arena);
    } else if (!strcmp(cmd, "ALLOC")) {
        int size = atoi(args[1]);
        printf("%d\n", alloc(arena, size));
    } else if (!strcmp(cmd, "FREE")) {
        // TODO: implement FREE
        // HINT: call a function :D
    } else if (!strcmp(cmd, "FILL")) {
        // TODO: implement FILL
        // HINT: call a function :D
    } else if (!strcmp(cmd, "SHOW")) {
        // TODO: implement SHOW
        // HINT: call a function :D
    } else if (!strcmp(cmd, "ALLOCALIGNED")) {
        // TODO: implement ALLOCALIGNED
        // HINT: call a function :D
    } else if (!strcmp(cmd, "REALLOC")) {
        // TODO: implement REALLOC
        // HINT: call a function :D
    } else if (!strcmp(cmd, "SHOW MAP")) {
        // TODO: implement SHOW MAP
        // HINT: call a function :D
    } else {
        fprintf(stderr, "[ERROR] unknown command (%s)\n", cmd);
    }
}

// free memory allocated for args
void cmd_free(int args_count, char *args[MAX_CMD_ARGS])
{
    for (int i = 0; i < args_count; ++i) {
        free(args[i]);
    }
}

int main(void)
{
    // cmd: cmd_name argument1 argument2 ...
    // args = {cmd_name, argument1, argument2, ... }
    // args_count = length of args
    int args_count;
    char *args[MAX_CMD_ARGS];

    arena_t *arena;
    arena = (arena_t *)malloc(sizeof(*arena));
    DIE(!arena, "malloc() failed\n");

    while (1) {
        // read new command from stdin
        if (!cmd_read(&args_count, args)) {
            break; // no command was found, break loop
        }

        cmd_execute(args_count, args, arena);  // execute command
        cmd_free(args_count, args); // free memory allocated for args
    }

    return 0;
}
