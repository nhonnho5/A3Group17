#include <stdio.h>
#include <stdlib.h>

#define FILENAME "test.txt"

void encrypt_file() {
    char ch;
    FILE *f, *temp;

    f = fopen(FILENAME, "r");
    if (f == NULL) {
        printf("File does not exist. \n");
    }

    temp = fopen("encrypted_passwords.txt", "w");
    while(1) {
        ch = fgetc(f);
        if (ch == EOF) {
            break;
        } else {
            ch = ch+100;
            fputc(ch, temp);
        }
    }

    fclose(f);
    fclose(temp);

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

    f = fopen("encrypted_passwords.txt", "r");
    if (f == NULL) {
        printf("File does not exist. \n");
    }
    
    temp = fopen(FILENAME, "w");

    while(1) {
        ch = fgetc(f);
        if (ch == EOF) {
            break;
        } else {
            ch = ch-100;
            fputc(ch, temp);
        }
    }

    fclose(f);
    printf("File decrypted \n");
}
int main() {


    return 0;
}
