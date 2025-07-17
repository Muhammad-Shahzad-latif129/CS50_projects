#include<stdio.h>
void pyramid(int height);

int main(void)
{
    int n;
    char c;
    while(1)
    {
        printf("Height: ");
        if(scanf("%i%c", &n, &c) != 2 || c!= '\n')
        {
            printf("Invalid Input. Please enter the valid input.\n");
            //Buffer Clear
            while(getchar() != '\n');
            continue;
        }
        if(n < 1 || n > 8)
        {
            Printf("Please enter the integer in the range 1 to 8.\n");
            continue;
        }   
    }       

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
