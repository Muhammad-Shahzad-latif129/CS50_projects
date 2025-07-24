#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool only_digit(char *argv);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
    if (argc < 2  || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!only_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    char text[100];
    printf("plaintext:  ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", rotate(text[i], key));
    }
    printf("\n");

}
bool only_digit(char *argv)
{
    for (int i = 0 , len = strlen(argv); i < len; i++)
    {
        if (!isdigit(argv[i]))
        {
            return false;
        }
    }
    return true;
}
char rotate(char c, int key)
{
        if (isupper(c))
        {
            return (c - 'A' + key) % 26 + 'A';
        }
        else if (islower(c))
        {
            return (c - 'a' + key) % 26 + 'a';
        }
        else
        {
            return c;
        }
}