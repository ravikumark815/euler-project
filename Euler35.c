/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

Author: https://github.com/ravikumark815

Answer: 55
*/

#include <stdio.h>
#include <stdint.h>

#define MAX 1000000

int8_t sieve[MAX];

int64_t rotate(int64_t n)
{
	int32_t n_digits, m;

	m = n;
	for (n_digits = 0; m > 0; m /= 10)
		++n_digits;

	for (m = 1; n_digits > 1; --n_digits)
		m *= 10;

	return m * (n%10) + n/10;
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

int32_t is_circular(int64_t n)
{
	int64_t rotated;

	if (!sieve[n])
		return 0;

	rotated = rotate(n);
	while (rotated != n)
	{
		if (!sieve[rotated])
			return 0;
		rotated = rotate(rotated);
	}

	return 1;
}


int32_t main(void)
{
	int32_t i, answer;

	init_sieve();
	for (i = 0, answer = 0; i < MAX; ++i)
		if (is_circular(i))
			++answer;

	printf("Result: %d\n", answer);
	return 0;
}