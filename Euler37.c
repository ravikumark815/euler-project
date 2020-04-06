/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

Author: https://github.com/ravikumark815

Answer: 748317
*/

#include <stdio.h>
#include <stdint.h>

#define MAX 1000000

int8_t sieve[MAX];

int32_t is_truncatable_prime(int64_t n)
{
	int64_t m;

	for (m = n; m > 0; m /= 10)
		if (!sieve[m])
			return 0;

	for (m = 1; n / m > 10; m *= 10)
		;
	for (n %= m; n > 0; m /= 10, n %= m)
		if (!sieve[n])
			return 0;

	return 1;
}

void init_sieve(void)
{
	int32_t i, j;

	for (i = 0; i < MAX; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	for (i = 2; i < MAX; ++i)
		if (sieve[i])
			for (j = 2*i; j < MAX; j += i)
				sieve[j] = 0;
}

int32_t main(void)
{
	int32_t i, answer;

	init_sieve();
	for (i = 8, answer = 0; i < MAX; ++i)
		if (is_truncatable_prime(i))
			answer += i;

	printf("Result: %d\n", answer);
	return 0;
}