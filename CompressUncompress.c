#include <stdio.h>
#include <stdlib.h>

#define FILENAME "encrypted_passwords.txt"
/*gcc -Wall -Werror -ansi -o CompressUncompress.out CompressUncompress.c -lm*/
/*CompressUncompress.out*/

void compress_file() {
    
    char currentChar;
    char previousChar = EOF;
    unsigned int count = 1;
    
    FILE *source, *destination;
    
    source = fopen(FILENAME, "r");

    if (source == NULL) { /*check if file exist*/
        printf("File does not exist. \n");
    }
    
    destination = fopen("compressed_passwords.txt", "w"); /*open a new file to write the new data*/

    int iteration = 0;

    while (1) {
        
        currentChar = fgetc(source); /*get next char in file. In the first iteration, the first char*/

        if (source == NULL){
            printf("File is empty. \n"); /*check if file is empty*/
            break;
        }
        if (currentChar == EOF) { /*check if the cursor is at the end of line*/
            break;
        }
        if (iteration == 0) { /*check fist iteration. Input a char '`' to mark it as has been compressed*/
            if (currentChar == '~'){
                printf("File has been encrypted. Compressing ...");
                currentChar = fgetc(source);
            }
            fputc('`', destination);
            fputc(currentChar, destination);
        } else if (currentChar == previousChar) { /*increase count if previous char is the same as this one*/
            count++;
        } else if (iteration > 0) {/*current char and previous char not match, output format Ex: a4. reset counter*/
            fprintf(destination, "%d", count);
            fputc(currentChar, destination);
            previousChar = currentChar;
            count = 1;
        } 
        
        previousChar = currentChar; /*let previousChar hold the same value as the current one, move onto the next one*/
        iteration++; /*count the iteration to separate it from the first one*/
        
        if (currentChar == '\n') { /*ì the file has multiple lines, reset the iteration count*/
            iteration = 0;
        }
    }

    fclose(destination);
    fclose(source);

    printf("File compressed \n");
}

void uncompress_file() {
    
    char currentChar;
    char previousChar = EOF;
    int count;
    
    FILE *source, *destination;

    source = fopen("compressed_passwords.txt", "r");

    if (source == NULL) { /*check if file exist*/
        printf("File does not exist. \n");
    }
    
    destination = fopen("encrypted_passwords.txt", "w"); /*open the new file to store the encrypted password*/

    currentChar = fgetc(source); /*check first char to see if file has been compressed*/

        if (currentChar != '`'){
            printf("File is not compressed yet. Please compressed file first.\n");
            fclose(source);
            return;
        }

    fputc('~', destination);

    while(1) {
        currentChar = fgetc(source);

        if (source == NULL){
            printf("File is empty. \n"); /*check if file is empty*/
            break;
        }
        if (currentChar == EOF) { /*end when get to end of file*/
            break;
        }
        /*get 2 char: previousChar indicate the characters that got compressed, 
        while the currentChar will be the number of time previousChar appear*/
        previousChar = currentChar; 
        currentChar = fgetc(source);

        sscanf(&currentChar, "%d", &count); /*convert currentChar to int*/
        
        while (count > 0) { /*decompress the string*/
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
