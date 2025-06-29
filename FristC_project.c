#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool is_digit(char*str); //function to check command-line argument is digit or not
char rotate(char c, int key); //Function to rotate the plain text

int main (int argc, char*argv[])
{
    // check whether there will be two command line argument
    if (argc < 2){
        printf("Usage: ./program_name key\n");
        return 1;
    }
    // To check is command-line is digit or not
    if (!is_digit(argv[1])){
        printf("Usage: ./program_name key\n");
        return 1;
    }
    //converting commandline string to integer for calculation
    int number = atoi(argv[1]);
    // User input for plain text
    char text[100];
    printf("Plaintext:  ");
    fgets(text, sizeof(text), stdin);
    //Calculating the length of plaintext
    int len = strlen(text);
    //To remove new line from (fgets) function
    if (len > 0 && text[len - 1] == '\n'){
        text[len - 1] = '\0';
    }
    //creating array for Ciphertext
    char cipher[100];
    // int strleng = strlen(text);

    for (int k = 0 ; k < len ; k++){
        cipher[k] = rotate(text[k] , number);
    }
    // If person right 26 it will give sam eplain text so thats why it is special case
    if (number == 26 || number == 0){
            printf("As it is.\n");
        }
    else{
        //Terminating the ciphertext array
        cipher[len] = '\0';
        printf("Ciphertext: %s\n", cipher);
    }  
}

bool is_digit(char*str)
{
    int leng = strlen(str);
    for (int j = 0 ; j<leng ; j++){
        if (!isdigit(str[j])){
            return false;
        }

    }
    return true;
        
}

char rotate(char c, int key)
{
    if (isalpha(c)){
        if (isupper(c)){
            return ((c - 'A' + key)%26 ) + 'A';
        }
        if (islower(c)){
            return ((c - 'a' + key)%26) + 'a';
        }       
    }   
    return c;
}

