/*
Problem 6 - Sum Square Difference

The sum of the squares of the first ten natural numbers is 385
The square of the sum of the first ten natural numbers is 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Answer: 25164150

Author: ravikumark815

*/

#include<stdio.h>

int main()
{
    int i=0,c=1,sum1=0,sum2=0;
    
    for(i=1;i<=100;i++)
    {
        sum1 = sum1+(i*i);
        sum2 = sum2+i;
    }

    printf("Result = %d\n",(sum2*sum2)-sum1);
    return 0;
}