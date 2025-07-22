#include<ctype.h>
#include<string.h>
//It contains the strlen function to calculate the length of the string
#include<stdio.h>

int score(char word[]);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2,4, 1, 8, 5,	1, 3, 1, 1,	3, 10, 1, 1, 1,	1, 4, 4, 8,	4, 10};
int main(void)
{
    char word1[100];
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0'; // Removing trailing newline

    char word2[100];
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0';

    int score1 = score(word1);
    int score2 = score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!.\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!.\n");
    }
    else
    {
        printf("Tie!.\n");
    }
    
}

int score(char word[])
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]) )
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]) )
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
    
}
