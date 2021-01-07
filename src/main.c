#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_usage() {
    printf("Usage:\n");
    printf(" -i <path>\n");
    printf(" -o <path>\n");
    printf(" -b\n");
    printf(" -d\n");

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
                    printf(input_path);
                    i += 2;
                    break; 
                case 'o':
                    output_path = argv[i+1];
                    printf(output_path);
                    i += 2;
                    break;
                case 'b':
                    binary_mode = true;
                    printf("Binary");
                    ++i;
                    break;
                case 'd':
                    decompression_mode = true;
                    printf("Decompresion");
                    ++i;
                    break;
                default:
                    print_usage();
            }
        } else {
             print_usage();
        }
    }

    return 0;
}