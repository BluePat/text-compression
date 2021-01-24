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

int binary_encoding(char *text_chunk, char *output_buf) {

    char buffer[3] = {0};

    int write_indx = 0;

    for (int i = 0; text_chunk[i] != '\0'; i++) { 

        uint8_t count = 1; 
        while (text_chunk[i] == text_chunk[i + 1] && count < 255) { 
            i++; 
            count++; 
        }
        
        snprintf(buffer, sizeof(buffer), "%d", count);
        fprintf(stdout, "%s", buffer);
        for (int j = 0; text_chunk[i] != '\0'; j++) {
            output_buf[write_indx] = buffer[j];
            write_indx += 1;
        }
        
        output_buf[write_indx] = (int) text_chunk[i];
        write_indx += 2;
    }
    
    output_buf[write_indx + 1] = '\0';
    return 0;
} 
