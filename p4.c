#include<stdio.h>

void pattern(char c, int n);

void main()
{
    printf("\n\nProgram to print the following pattern: \n\n");

    printf("  $  \n $$$ \n$$$$$\n $$$ \n  $  \n\n");

    printf("Enter the character you want to print in the pattern mentioned above: ");
    char c;
    scanf("%c", &c);

    printf("Enter the number of rows (Odd number only) of the pattern to be printed: ");
    int n;
    do // Input validation for "n".
    {
        scanf("%d", &n);
        if(n < 0 || n % 2 == 0)
        printf("Number of rows are odd whole numbers only. Enter again: ");
    } while (n < 0 || n % 2 == 0);

    printf("\nPattern: \n\n");

    pattern(c,n);

    printf("\n\n");
}

void pattern(char c, int n)
{
    int k = (n+1) / 2; // k is only used in the first if block. // k contains the position of the centre row and according to the pattern the centre most row is same as the centre most column which is used to print the empty spaces in each row till the centre row. Number of spaces before the first character in 1st row is therefore from 1 to less than k as k contains the position of the first character in the first row. For second row k is decremented by one and no. of spaces for second row is from 1 to less than k. And so on.
    int p = 1; // p is only used in the second if block. // Explanation of it is below --1
    int q;
    for(int i = 1; i <= n; i++) // loop over all the rows
    {
        if(i <= ((n+1) / 2)) // Pattern logic from the first row till the centre row.
        {
            for(int j = 1; j < k; j++) // This loop is to print empty spaces in each row before the first character in that row.
            {
                printf(" ");  
            }
            for(int j = 1; j <= 2*i - 1; j++) // After printing the empty spaces, printing the characters in that row. ith row contains the ith odd number of characters.
            {
                printf("%c", c); 
            }
            for(int j = 1; j < k; j++) // This loop is to print empty spaces in each row after the last character in that row. We reach the position till last character and then after the last character from the loop just above. Number of spaces are same before the 1st character and after the last character in that row. Therefore, same loop for printing spaces before and after the characters in that row is used.
            {
                printf(" ");  
            }
            printf("\n"); // row advancement
            k--; // Explained its usage in the comment after the declaration of k above.
        }

        if(i > ((n+1) / 2)) // Pattern logic after the centre row till the last row. Contains opposite logic of the above due to the pattern's characteristics.
        {
            // For the characters' printing logic: Instead of applying a converse logic directly of the above if block, we are using the converse indirectly by shifting the row values as explained in the next comment below and going in the opposite direction, that is, from the row before the centre row towards the 1st row due to the shifting as we move down from after the centre to the last row using i values and then using the i value, p value and the subtraction we are moving upwards consecutively(this is the shifting) from the row before the centre row to the 1st row one by one.
            q = i - 2*p; // Here we are shifting (like origin shifting in coordinates). ith row contains qth = (i - 2*p)th odd number of characters(See above if block's comments for the reason) which is = 2*q - 1 characters. i - 2*p shifts the ith row to (i - 2*p)th row which is = qth row. According to the pattern. The rows centre row + 1 and centre row - 1 are same then centre row + 2 and centre row - 2 are same and so on. Generalising: centre row - s = centre row + s. As p contains the row position as first row after the centre row (initially p = 1) and it increments by one for each upcoming consecutive row, general condition becomes: centre row - p = centre row + p Difference between these two rows is of 2*p and therefore shifting the rows from ith row by 2*p rows (i and p increment by one in each loop execution) behind gives us = (i - 2*p)th row which is same as the ith row.
            for(int j = 1; j <= p; j++) // This loop is to print empty spaces in each row before the first character in that row. // --1, --2: From after the centre row the empty spaces increases from 1 by 1 in each consecutive upcoming row. Due to this p is intially declared as 1 above. And p is incremented below by 1 for each upcoming consecutive row. // Here a direct converse of the above if block is used in terms of decreasing spaces in the above if block and increasing spaces in this if block.
            {
                printf(" ");  
            }
            for(int j = 1; j <= 2*q - 1; j++) // After printing the empty spaces, printing the characters in that row. Logic explained in the above comments.
            {
                printf("%c", c);  
            }
            for(int j = 1; j <= p; j++) // This loop is to print empty spaces in each row after the last character in that row. We reach the position till last character and then after the last character from the loop just above. Number of spaces are same before the 1st character and after the last character in that row. Therefore, same loop for printing spaces before and after the characters in that row is used.
            {
                printf(" ");  
            }
            printf("\n"); // row advancement
            p++; // Explanation of it is above --2
        }
    } 
}