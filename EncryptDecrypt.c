#include <stdio.h>
#include <stdlib.h>

#define FILENAME "test.txt"

void encrypt_file() {
    char ch;
    FILE *f, *temp;
    
    /* password file needs to be created before encrypting */
    f = fopen(FILENAME, "r");
    if (f == NULL) {
        printf("File does not exist. \n");
    }
    
    /* creating temp file */
    temp = fopen("encrypted_passwords.txt", "w");
    
    while(1) {
        ch = fgetc(f);
        if (ch == EOF) {
            break;
        } else {         /* using substitution ciphering to encrypt data */
            ch = ch+100; /* value shift to the right 100 values */
            fputc(ch, temp);
        }
    }

    fclose(f);
    fclose(temp);

    /* encrypting initial file by copying contents of the temp file */
    f = fopen(FILENAME, "w");
    temp = fopen("encrypted_passwords.txt", "r");
    while (1) {
        ch = fgetc(temp);
        if (ch == EOF) {
            break;
        } else {
            fputc(ch, f);
        }
    }

    fclose(f);
    fclose(temp);
    printf("File encrypted \n");
}

void decrypt_file() {
    char ch;
    FILE *f, *temp;

    /* reading from encrypted file */
    f = fopen("encrypted_passwords.txt", "r");
    if (f == NULL) {
        printf("File does not exist. \n");
    }
    
    /* changnig contents of initial file */
    temp = fopen(FILENAME, "w");
    
    while(1) {
        ch = fgetc(f);
        if (ch == EOF) {
            break;
        } else {
            ch = ch-100; /* shifting values back to original characters */
            fputc(ch, temp);
        }
    }

    fclose(f);
    printf("File decrypted \n");
}
int main() {


    return 0;
}
