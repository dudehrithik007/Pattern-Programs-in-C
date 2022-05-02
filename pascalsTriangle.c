#include <stdio.h>
#include <math.h>

void pascalsTriangle(int n);
long C(int n, int r);
long factorial(int n);

void main()
{
    printf("\n\nProgram to print the Pascal's Triangle till the specified number of rows as entered by the user.\n\n");

    printf("Enter the number of rows: ");
    int n;
    scanf("%d", &n);

    printf("\n\nPascal's Triangle till %d rows:\n\n", n);

    pascalsTriangle(n);

    printf("\n\n");
}

void pascalsTriangle(int n) // By studying the pattern and the relations between the row value, the column value and the values in the pattern, we deduce the following algorithm:
{
    for(int i = 1; i <= n; i++) // Each iteration corresponds to each row.
    {
        for(int j = i; j <= n-1; j++) // for ith row, there are n-i spaces. Or we can say from i to n-1, there are ((n-1) - i) + 1 spaces = n-i spaces.
            printf(" "); // Number of spaces in each row before the first value is printed below. The number of spaces are used to form the 'triangle' structure.
            
        for(int j = 1; j <= i; j++) // for ith row, in nCr, n = i - 1 and r = from 0 to i-1 (which is n).
        {
            printf("%ld ", C(i-1, j-1)); 
        }
        printf("\n");
    }
}

long C(int n, int r) // long is used for storing very large numbers. // returns nCr. // Pascal's Triangle's each value is a value = number of combinations of 'n' different objects taken 'r' at a time without repetition.
{
    return (factorial(n)) / (factorial(n-r) * factorial(r));
}

long factorial(int n) // long is used for storing very large numbers.
{
    long fact = 1; // initially it is 1 so that if n = 0, we don't enter the loop and we return 1 as 0! = 1. Also, if n != 0, then too in the loop, multiplications starts from initial value of i which is 1 itself till n. So, initially, we get 1*1 = 1 (if n >= 1), and so on (if n > 1).

    for(long i = 1; i <= n; i++)
        fact = fact * i;
    
    return fact;
}