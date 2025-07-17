#include<stdio.h>
#include<string.h>

int main(void)
{
    char name[60];
    printf("What's your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s\n", name);
    return 0;
}