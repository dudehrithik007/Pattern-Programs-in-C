#include<stdio.h>

void pattern(int n);

void main()
{
    printf("\n\nProgram to print the following pattern: \n\n");

    printf("  1  \n 222 \n33333\n 444 \n  5  \n\n");

    printf("Enter the number of rows (Odd number only) of the pattern to be printed: ");
    int n;
    do // Input validation for "n".
    {
        scanf("%d", &n);
        if(n < 0 || n % 2 == 0)
        printf("Number of rows are odd whole numbers only. Enter again: ");
    } while (n < 0 || n % 2 == 0);

    printf("\nPattern: \n\n");

    pattern(n);

    printf("\n\n");
}

// Explanation same as p4.c except here we are printing the i values: --1
void pattern(int n)
{
    if(n % 2 == 1) // Alternative input validation for "n".
    {
        int k = (n+1) / 2;
        int p = 1;
        int q;
        for(int i = 1; i <= n; i++)
        {
            if(i <= ((n+1) / 2))
            {
                for(int j = 1; j < k; j++)
                {
                    printf(" ");  
                }
                for(int j = 1; j <= 2*i - 1; j++)
                {
                    printf("%d", i); // --1
                }
                for(int j = 1; j < k; j++)
                {
                    printf(" ");  
                }
                printf("\n");
                k--;
            }

            if(i > ((n+1) / 2))
            {
                q = i - 2*p;
                for(int j = 1; j <= p; j++)
                {
                    printf(" ");  
                }
                for(int j = 1; j <= 2*q - 1; j++)
                {
                    printf("%d", i); // --1
                }
                for(int j = 1; j <= p; j++)
                {
                    printf(" ");  
                }
                printf("\n");
                p++;
            }
        }
    }
}