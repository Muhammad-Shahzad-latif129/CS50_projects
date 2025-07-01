#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[100];
    int age;
    printf("Enter your name: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    printf("Enter your age: ");
    scanf("%i", &age);
    if (age < 18)
    {
        printf("%s you are not eligible for age %i\n", s, age);
    }
    if(age <= 0)
    {
        printf("%s please enter the valid age.\n", s);
    }
    else
    {
        printf("%s you are eligible.\n", s);
    }
    
    printf("This is the end of Program.....\n");
    return 0;
}
