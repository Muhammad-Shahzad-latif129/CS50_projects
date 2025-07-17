#include<stdio.h>
//For the strcspn
#include<string.h>

int main(void)
{
    char name[60];
    printf("What's your name? ");
    fgets(name, sizeof(name), stdin);
    //Remove the \n from the buffer
    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s\n", name);
    return 0;
}
