/*
Problem 5 - Smallest Multiple

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Answer: 232792560

Author: ravikumark815

*/

#include<stdio.h>

int main()
{
    int i=0,c=1,res=2521;
    while(c)
    {   
        c=0;
        for(i=11;i<20;i++)
        {
            if(res%i!=0)
            {
                c = 1;
                break;
            }
        }
        res+=1;
    }
    printf("Result = %d\n",res-1);
}