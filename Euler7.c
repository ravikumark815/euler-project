/*
Problem 7 - 10001st Prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10001st prime number?

Answer: 104743

Author: ravikumark815

*/

#include<stdio.h>

int isprime(int n);

int main()
{
    int i=2,j=0,c=1,res = 0;
    
    while(c<10002)
    {
        if (isprime(i))
        {
            c+=1;
            res = i;
        }
        i+=1;
    }
    printf("Result = %d\n",res);
    return 0;
}

int isprime(int n)
{
    if (n==1||n==2) return 1;
    else if (n%2==0)return 0;
    else
    {
        for(int i=3;i<n/2;i+=2)
        {
            if(n%i==0)
                return 0;
        }
        return 1;
    }
}