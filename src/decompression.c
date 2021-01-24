#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int length_decoding(char *text_chunk, char *output_buf) {

    int write_indx = 0;
    for (int i = 0; text_chunk[i] != '\0'; i++) {
        if ( isdigit(text_chunk[i]) ) {

            int count = text_chunk[i] - '0';
            while (count > 0) {
                output_buf[write_indx] = text_chunk[i + 1];
                count--;
                write_indx++;
            }

            i++;
        }
    }

    output_buf[write_indx] = '\0';
    return 0;
}

int binary_decoding(char *text_chunk, char *output_buf) {

    int write_indx = 0;
    int i = 0;
    while (text_chunk[i] != '\0') { 
        
        write_indx += sprintf(&output_buf[write_indx], "%d %d", text_chunk[i], text_chunk[i+1]);
        output_buf[write_indx] = ' ';
        
        write_indx += 1;
    }
    
    output_buf[write_indx + 1] = '\0';
    fprintf(stdout, "%s", output_buf);
    return 0;
} 
