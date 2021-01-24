#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *input_path;
    char *output_path;
    bool binary_mode;
    bool decompression_mode;
} RunMode;

void error_on_improper_use() {
    fprintf(stderr, "ERROR: Failed to parse command line arguments. See README.md for command line input troubleshooting.");
    exit(1);
}

RunMode parse_command_line_args(int argc, char* argv[]) {
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

    RunMode run_mode = {
        .binary_mode = binary_mode,
        .decompression_mode = decompression_mode,
        .input_path = input_path,
        .output_path = output_path
        };

    return run_mode;
}
