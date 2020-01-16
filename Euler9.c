/*
Problem 9 - Special Pythagorean Triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Answer: 31875000

Author: ravikumark815

*/

#include<stdio.h>

int main()
{
    int a=0,b=0,c=0;
    for(a=1;a<1000;a++)
    {
        for(b=a+1;b<1000-a;b++)
        {
            c=1000-(a+b);
            if((c*c)==(a*a)+(b*b))
            {
                printf("Result = %d\n",a*b*c);
            }
        }
    }
    return 0;
}