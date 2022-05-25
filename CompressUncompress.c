#include <stdio.h>
#include <stdlib.h>

#define FILENAME "encrypted_passwords.txt"
/*gcc -Wall -Werror -ansi -o CompressUncompress.out CompressUncompress.c -lm*/
/*CompressUncompress.out*/

void compress_file() {
    FILE *source, *destination;
    
    source = fopen(FILENAME, "r");
    if (source == NULL) {
        printf("File does not exist. \n");
    }
    
    destination = fopen("compressed_passwords.txt", "w");

    char currentChar;
    char previousChar = EOF;
    unsigned int count = 1;

    int iteration = 0;

    while (1) {
        
        currentChar = fgetc(source); /*get next char*/
        
        if (currentChar == EOF) { /*check if the cursor is at the end of line*/
            break;
        }
        if (iteration == 0) { /*check fist iteration*/
            fputc(currentChar, destination);
        } else if (currentChar == previousChar) { /*increase count if previous char is the same as this one*/
            count++;
        } else if (iteration > 0) {/*current char and previous char not match, output format Ex: a4. reset counter*/
            fprintf(destination, "%d", count);
            fputc(currentChar, destination);
            previousChar = currentChar;
            count = 1;
        } 
        
        previousChar = currentChar; /*let previousChar hold the same value as this one, move onto the next one*/
        iteration++;
        
        if (currentChar == '\n') { /*check for password in the file*/
            iteration = 0;
        }

    }
    fclose(destination);
    fclose(source);
}

void uncompress_file() {
    char currentChar;
    char previousChar = EOF;
    int count;
    FILE *source, *destination;

    source = fopen("compressed_passwords.txt", "r");
    if (source == NULL) {
        printf("File does not exist. \n");
    }
    
    destination = fopen("encrypted_passwords.txt", "w");


    while(1) {
        currentChar = fgetc(source);
        
        if (currentChar == EOF) {
            break;
        } 
        
        if (currentChar == '\n') { 
            currentChar = fgetc(source);
            fputc('\n', destination);
        }
        
        previousChar = currentChar;
        currentChar = fgetc(source);

        sscanf(&currentChar, "%d", &count);
        
        while (count > 0) {
            fputc(previousChar, destination);
            count--;
        }
    }

    fclose(destination);
    fclose(source);
    printf("File uncompressed \n");
}
int main() {

    uncompress_file();

    return 0;
}

