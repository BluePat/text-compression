#include <stdio.h>
#include <stdlib.h>

int length_encoding(char *text_chunk, char *output_buf) {

    int write_indx = 0;
    for (int i = 0; text_chunk[i] != '\0'; i++) { 
        
        int count = 1; 
        while (text_chunk[i] == text_chunk[i + 1] && count < 9) { 
            i++; 
            count++; 
        }
        
        output_buf[write_indx] = count + '0';
        output_buf[write_indx + 1] = text_chunk[i];
        write_indx += 2;
    }
    
    output_buf[write_indx + 1] = '\0';
    return 0;
} 
