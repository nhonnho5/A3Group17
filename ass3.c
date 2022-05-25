/******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 3
 * Name: Cassius Makda
 * Student ID: 24536599

 * Name: Tan Tri Ngo
 * Student ID: 13482029

 * Name: Uy Ly
 * Student ID: 13882004

 * Description:
 * This is a program that...
******************************************************************************/
/* gcc -Werror -Wall -ansi -o ass3.out ass3.c -lm */
#include <stdio.h>
#include "compress.h" /* contains our compression functions */
#inlcude "encrypt.h" /* contains our encryption functions */
/******************************************************************************
 * Function prototypes 
******************************************************************************/
void printMenu(void);


int main()
{
    printMenu();
        int input;
    do
    {
        printMenu();
        scanf(" %d", &input);
        while (getchar() != '\n') {}
        if (input < 1 || input > 6)
        {
            printf("You entered an invalid choice. Try again.");
        }
        else 
        { 
            switch(input) 
            {
                case 1:
                encrypt_file();
                break;

                case 2:
                decrypt_file();
                break;

                case 3:

                break;

                case 4:

                break;

            }
        }
    } while(input !=5);
    return 0;
}

void printMenu(void){
    printf("\n\n"
     "1. Encrypt a file.\n"
     "2. Decrypt a file (requires an encrypted file).\n"
     "3. Compress a file.\n"
     "4. Decompress a file (requires a compressed file).\n"
     "5. Close the program.\n"
     "NOTE: This program overwrites the output file(s) whenever \n
     decompression or decryption is run. Save your content first!\n"
     "Enter your choice>\n");
}
