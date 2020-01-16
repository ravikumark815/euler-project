/*
Problem 3 - Largest Prime Factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer: 6857

Author: ravikumark815

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned long long n=600851475143;
    unsigned long long i;

    for(i=2ULL;i<n;i++)
    {
        while(n%i==0)
        {
            n/=i;
        }
    }
    printf("Result = %llu\n",n);
    return 0;
}