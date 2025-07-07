#include <stdio.h>
#include <string.h>
#include <ctype.h>
void Upper_case(char *str);
int main(void)
{
    char s[100];
    int age;
    char w[5];
    printf("Enter your name: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("Enter your age: ");
    scanf("%i", &age);
    getchar();
    if (age < 18)
    {
        printf("%s you are not eligible for age %i\n", s, age);
        return 1;
    }
    else if(age <= 0)
    {
        printf("%s please enter the valid age.\n", s);
        return 2;
    }
    else
    {
        printf("%s you are eligible.\n", s);
    }
    printf("Which license you want\nFor Four Wheel write FW\nFor Two Wheel write TW: \n");
    fgets(w, sizeof(w), stdin);
    Upper_case(w);
    w[strcspn(w, "\n")] = '\0';

    if (strcmp(w, "TW") == 0)
    {        
        printf("OK here is the Two Wheel vehicle license\n");
    }
    else if (strcmp(w, "FW") == 0)
    {
        if (age < 20)
        {
            printf("%s you are not eligible for the %s license with the %i age.\n", s, w, age);
        }
        else
        {
            printf("OK here is the Four Wheel vehicle license\n");
        }
        
    }
    else
    {
        printf("Enter the valid input from the \nTW or \nFW\n");
    }
    
    
    printf("This is the end of Program.....\n");
    return 0;
}

void Upper_case(char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}
