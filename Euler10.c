/*
Problem 10 - Summation of Primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below 2000000.
Developed using Sieve of Eratosthenes Algorithm

Answer: 142913828922

Author: ravikumark815

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *soe;
    unsigned i, j;
    size_t n = 2000000;
    unsigned long long sum = 0ULL;

    soe = calloc(n, sizeof *soe);
    for (i = 2; i < n; i++) {
        if (!soe[i]) {
        sum += i;
        for (j = i*2; j < n; j += i) {
            soe[j] = 1;
        }
        }
    }
    free(soe);

    printf("Result = %llu\n", sum);

    return 0;
}