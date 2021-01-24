#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

void error_on_improper_use() {
    fprintf(stderr, "ERROR: Failed to parse command line arguments. See README.md for command line input troubleshooting.");
    exit(8);
}

int main(int argc, char* argv[]) {

    char *input_path = {0};
    char *output_path = {0};

    bool binary_mode = false;
    bool decompression_mode = false;

    int i = 1;
    while (i < argc) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {

                case 'i':
                    input_path = argv[i+1];
                    fprintf(stdout, "INFO: Path to input file: %s\n", input_path);
                    i += 2;
                    break;

                case 'o':
                    output_path = argv[i+1];
                    fprintf(stdout, "INFO: Path to output file: %s\n", output_path);
                    i += 2;
                    break;

                case 'b':
                    binary_mode = true;
                    fprintf(stdout, "INFO: Binary mode enabled\n");
                    ++i;
                    break;

                case 'd':
                    decompression_mode = true;
                    fprintf(stdout, "INFO: Decompression mode enabled\n");
                    ++i;
                    break;
                    
                default:
                    error_on_improper_use();
            }
        } else {
             error_on_improper_use();
        }
    }
    
    read_text(input_path);

    return 0;
}
