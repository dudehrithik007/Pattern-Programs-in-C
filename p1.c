#include<stdio.h>

void pattern(char c, int n);

void main()
{
    printf("\n\nProgram to print the following pattern: \n\n");

    printf("$\n$$\n$$$\n$$$$\n$$$$$\n\n");

    printf("Enter the character you want to print in the pattern mentioned above: ");
    char c;
    scanf("%c", &c);

    printf("Enter the number of rows of the pattern to be printed: ");
    int n;
    do // Input validation for "n".
    {
        scanf("%d", &n);
        if(n < 0)
        printf("Number of rows are whole numbers only. Enter again: ");
    } while (n < 0);
    

    printf("\nPattern: \n\n");

    pattern(c,n);

    printf("\n\n");
}

void pattern(char c, int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++) 
        {
            printf("%c", c);
        }  
        printf("\n");
    }   
}