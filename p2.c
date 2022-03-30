#include<stdio.h>

void pattern(int n);

void main()
{
    printf("\n\nProgram to print the following pattern: \n\n");

    printf("1\n12\n123\n1234\n12345\n\n");

    printf("Enter the number of rows of the pattern to be printed: ");
    int n;
    do // Input validation for "n".
    {
        scanf("%d", &n);
        if(n < 0)
        printf("Number of rows are whole numbers only. Enter again: ");
    } while (n < 0);

    printf("\nPattern: \n\n");

    pattern(n);

    printf("\n\n");
}

void pattern(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++) 
        {
            printf("%d", j);
        }  
        printf("\n");
    } 
}