#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int count_letters(char string[]);
int count_words(char string[]);
int count_sentence(char string[]);

int main(void)
{
    char text[500];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    int words = count_words(text);
    int Letters = count_letters(text);
    int sentence = count_sentence(text);

    float L = (float) Letters / words * 100;
    float S = (float) sentence / words *100;
    
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+.\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1.\n");
    }
    else
    {
        printf("Grade %.0f.\n", round(index));
    }
    
}
int count_letters(char string[])
{
    int sum = 0;
    for(int i = 0, len = strlen(string); i < len; i++)
    {
        if (isalpha(string[i]))
        {
            sum += 1;
        }
    }
    return sum;
} 
int count_words(char string[])
{
    int count = 0;
    for (int i = 1, l = strlen(string); i < l; i++)
    {
        char c = string[i];
        if (c == ' ')
        {
            count += 1;
        }
    }
    return count + 1;
}
int count_sentence(char string[])
{
    int count = 0;
    for (int i = 0, l = strlen(string); i < l; i++)
    {
        char c = string[i];
        if (c == '.' || c == '!' || c == '?')
        {
            count += 1;
        }
    }
    return count;
}