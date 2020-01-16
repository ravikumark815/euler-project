/*
Problem 4 - Largest Prime Factor

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.

Answer: 906609

Author: ravikumark815

*/

#include<stdio.h>

int palindrome(int n);

int main()
{
    int i=0,j=0,res=0;
    for(i=100;i<=999;i++)
    {
        for(j=100;j<=999;j++)
        {
            if(i*j==palindrome(i*j) && i*j>res)
                res = i*j;
        }
    }
    printf("Result = %d\n",res);
    return 0;
}

int palindrome(int n)
{
    int rev=0;
    while(n){
        rev = 10*rev+n%10;
        n/=10;
    }
    return rev;
}