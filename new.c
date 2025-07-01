#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[100];
    printf("Enter your name: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    for (int i = 0; i < 5; i++)
    {
        printf("Your name is: %s\n", s);
    }
    return 0;
}
