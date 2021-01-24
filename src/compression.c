#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

int length_encoding(char *text_chunk, char *output_buf) {

    int write_indx = 0;
    for (int i = 0; text_chunk[i] != '\0'; i++) { 
        
        int count = 1; 
        while (text_chunk[i] == text_chunk[i + 1] && count < 9) { 
            i++; 
            count++; 
        }
        
        write_indx += sprintf(&output_buf[write_indx], "%d%c", count, text_chunk[i]);
    }
    
    output_buf[write_indx] = '\0';
    return 0;
} 

int binary_encoding(char *text_chunk, char *output_buf) {

    int write_indx = 0;

    for (int i = 0; text_chunk[i] != '\0'; i++) { 

        int count = 1; 
        while (text_chunk[i] == text_chunk[i + 1] && count < 255) { 
            i++; 
            count++; 
        }
        
        write_indx += sprintf(&output_buf[write_indx], "%d %d", count, text_chunk[i]);
        output_buf[write_indx] = ' ';
        
        write_indx += 1;
    }
    
    output_buf[write_indx + 1] = '\0';
    return 0;
} 
