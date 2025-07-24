#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

bool check(char *key);
bool repeatation_check(char *key);
void substitution(char *text, char *key);

int main(int argc, char *argv[])
{
    if (argc != 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!check(argv[1]))
    {
        return 1;
    }
    
    if (!repeatation_check(argv[1]))
    {
        return 1;
    }
    
    char text[100];
    printf("plaintext:  ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    
    //Substituted ciphertext
    substitution(text, argv[1]);
    return 0;
}
bool check(char *key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (isdigit(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return false;
        }   
        else if (!isdigit(key[i]) && len < 26 || len > 26)
        {
            printf("Key must contain 26 Caharacters\n");
            return false;
        }
    }     
    return true; 
}
bool repeatation_check(char *key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (key[i] == key[i + 1])
        {
            printf("Key must not contain the repeated characters\n");
            return false;
        }
        
    }
    return true;
}
void substitution(char *text, char *key)
{
    char cipher[100];
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        cipher[i] = text[i];
        if (isupper(cipher[i]))
        {
            cipher[i] = key[(cipher[i] - 'A') % 26]; 
        }
        else if (islower(cipher[i]))
        {
            cipher[i] = key[(cipher[i] - 'a') % 26];
        }
        else
        {
            cipher[i] = cipher[i];
        }
    }
    printf("ciphertext: %s\n", cipher);
}