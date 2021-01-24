#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "command_line_args.c"
#include "compression.c"
#include "decompression.c"

#define CHUNK 1024

/** Read text file from a given path and save it to the memory */
char* read_text(char* input_path) {

    char *input_buf = malloc(CHUNK);
    if (input_buf == NULL) {
        fprintf(stderr, "ERROR: while allocating memory");
        exit(1);
    }

    size_t nread;

    FILE *file = fopen(input_path, "r");

    if (file == NULL) {
        fprintf(stderr, "ERROR: while trying to open %s for reading\n", input_path);
        exit(1);
    }

    while ((nread = fread(input_buf, 1, CHUNK, file)) > 0) {
        //fwrite(input_buf, 1, nread, stdout);
    }

    fclose(file);

    return input_buf;
}

int main(int argc, char* argv[]) {

    char *output_buf = malloc(CHUNK);

    char* test_buffer = malloc(CHUNK);

    RunMode run_mode = parse_command_line_args(argc, argv);
    char *text_chunk = read_text(run_mode.input_path);
    length_encoding(text_chunk, output_buf);
    fprintf(stdout, "%s", output_buf);


    fprintf(stdout, "\nDECODING:\n");
    length_decoding(output_buf, test_buffer);
    fprintf(stdout, "%s", test_buffer);

    free(test_buffer);
    free(text_chunk);
    free(output_buf);
    return 0;
}
