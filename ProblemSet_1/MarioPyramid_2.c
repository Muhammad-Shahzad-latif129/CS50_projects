#include<stdio.h>
void pyramid(int height);

int main(void)
{
    int n;
    int b = 1;
    do
    {
        printf("Height: ");
        scanf("%i", &n);
    } while (n < 1 || n>8);

    pyramid(n);
}

void pyramid(int height)
{
    //Right-aigned pyramid
    for(int i = 1; i <= height; i++)
    {
        for(int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < i; k++)
        {
            printf("#");
        }
        //Space between them
        printf("  ");
        //Left-alogned pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }  
        printf("\n");
    }
}
