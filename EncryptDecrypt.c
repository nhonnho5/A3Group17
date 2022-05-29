#include <stdio.h>
#include <stdlib.h>

#define FILENAME "test.txt"
int key;

/*gcc -Wall -Werror -ansi -o EncryptDecrypt.out EncryptDecrypt.c -lm*/
/*./EncryptDecrypt.out*/

void encrypt_file() {
    char ch;
    FILE *f, *temp;
    
    /* password file needs to be created before encrypting */
    f = fopen(FILENAME, "r");
    if (f == NULL) {
        printf("File does not exist. \n");
    }
    
    temp = fopen("encrypted_passwords.txt", "w");

    printf("Enter a 3 digit pin to encrypt file\n");
    scanf("%3d", &key);

    fputc('~', temp); /*input checker character to see if the file has been encrypted*/
    
    while(1) {
        ch = fgetc(f);
        if (f == NULL){
            printf("File is empty. \n"); /*check if file is empty*/
            break;
        }
        if (ch == EOF) {
            break;
        } else {         /* using substitution ciphering to encrypt data */
            ch = ch+key; /* value shift to the right equal to the value of key */
            fputc(ch, temp);
        }
    }

    fclose(f);
    fclose(temp);

    /* encrypting initial file by copying contents of the temp file */
    /*f = fopen(FILENAME, "w");
    temp = fopen("encrypted_passwords.txt", "r");
    
    while (1) {
        ch = fgetc(temp);
        if (ch == EOF) {
            break;
        } else {
            fputc(ch, f);
        }
    }*/

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

    ch = fgetc(f);
    if (ch != '~'){
        printf("File is not encrypted. Please encrypt the file first. \n");
        fclose(f);
        return;
    }

    printf("Enter a 3 digit pin to decrypt file\n");
    scanf("%3d", &key);
    
    /* changing contents of initial file */
    temp = fopen(FILENAME, "w");
    
    while(1) {
        ch = fgetc(f);
        if (f == NULL){
            printf("File is empty. \n"); /*check if file is empty*/
            break;
        }
        if (ch == EOF) {
            break;
        } else {
            ch = ch-key; /* shifting values back to original characters */
            fputc(ch, temp);
        }
    }

    fclose(f);
    printf("File decrypted \n");
}
int main() {

    decrypt_file();
    return 0;
}
