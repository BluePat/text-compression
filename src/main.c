#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "command_line_args.c"

#define CHUNK 1024

/** Read text file from a given path and save it to the memory */
char* read_text(char* input_path) {

    char *buf = malloc(CHUNK);
    if (buf == NULL) {
        fprintf(stderr, "ERROR: while allocating memory");
        exit(1);
    }

    size_t nread;

    FILE *file = fopen(input_path, "r");

    if (file == NULL) {
        fprintf(stderr, "ERROR: while trying to open `%s' for reading\n", input_path);
        exit(1);
    }

    while ((nread = fread(buf, 1, CHUNK, file)) > 0) {
        fwrite(buf, 1, nread, stdout);
    }

    fclose(file);

    return buf;
}

int main(int argc, char* argv[]) {

    RunMode run_mode = parse_command_line_args(argc, argv);
    read_text(run_mode.input_path);

    return 0;
}
