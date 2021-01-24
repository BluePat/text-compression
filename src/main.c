#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "command_line_args.c"
#include "compression.c"
#include "decompression.c"

#define CHUNK 1024

/** Read text file from a given path and save it to the memory */
size_t read_text(char *input_path, char *input_buf) {

    size_t nread;

    FILE *file = fopen(input_path, "r");

    if (file == NULL) {
        fprintf(stderr, "ERROR: while trying to open %s for reading\n", input_path);
        exit(1);
    }

    nread = fread(input_buf, 1, CHUNK, file);
    fclose(file);

    return nread;
}

/** Save modified text to file in a given path */
void save_text(char *output_path, char *output_buf, size_t nread) {

    FILE *file = fopen(output_path, "w");

    if (file == NULL) {
        fprintf(stderr, "Error: while trying to open %s for writing\n", output_path);
        exit(1);
    }

    fwrite(output_buf, 1, nread, stdout);

    fclose(file);
}

int main(int argc, char* argv[]) {

    RunMode run_mode = parse_command_line_args(argc, argv);

    char *input_buf = malloc(CHUNK);
    if (input_buf == NULL) {
        fprintf(stderr, "ERROR: while allocating memory");
        exit(1);
    }

    char *output_buf = malloc(CHUNK);
    if (output_buf == NULL) {
        fprintf(stderr, "ERROR: while allocating memory");
        exit(1);
    }

    size_t nread = read_text(run_mode.input_path, input_buf);

    if (run_mode.binary_mode) {
        if (run_mode.decompression_mode) {
            binary_decoding(input_buf, output_buf);
        } else {
            binary_encoding(input_buf, output_buf);
        }
    } else {
        if (run_mode.decompression_mode) {
            length_decoding(input_buf, output_buf);
        } else {
            length_encoding(input_buf, output_buf);
        }
    }

    save_text(run_mode.output_path, output_buf, nread);

    free(input_buf);
    free(output_buf);
    return 0;
}
