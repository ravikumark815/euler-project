/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

Author: https://github.com/ravikumark815

Answer: 121313
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 1000000

uint8_t sieve[N];

/* init_sieve: init the array to test integer primality (Eratosthenes sieve) */
void init_sieve(void)
{
	int32_t i, j;

	/* at first, all integers are considered to be prime */
	for (i = 0; i < N; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	/* when a prime is found, mark all its mutiples as non-prime */
	for (i = 2; i < N; ++i)
		if (sieve[i])
			for (j = 2*i; j < N; j += i)
				sieve[j] = 0;
}

/* generate_number: replace '1' in patern[] with the repeated digit and '0' with
 * a non-repeated digit (e.g. generate_number([1, 0, 0, 1], 4, 7, 19) = 7917) */
int32_t generate_number(uint8_t *pattern, int32_t len,
		        int32_t repeated, int32_t non_repeated)
{
	uint8_t *digits;  /* digits of the generated number */
	int32_t i, number;

	/* read the pattern, place the digits according to the rule */
	digits = calloc(len, sizeof *digits);
	for (i = 0; i < len; ++i)
	{
		if (pattern[i] == 1)
			digits[i] = repeated;
		else
		{
			digits[i] = non_repeated%10;
			non_repeated /= 10;
		}
	}

	/* create an integer based on the digits array ([1, 3, 7] -> 137) */
	number = 0;
	for (i = 0; i < len; ++i)
		number = 10*number + digits[i];
	return number;
}

/* find_family_length: generate all possible numbers given the pattern and the
 * non-repeated digits, changing the repeated digit for each number (0..9).
 * Return how many of these numbers are prime. */
int32_t family_length(uint8_t *pattern, int len,
		      int32_t repeated, int32_t non_repeated)
{
	int32_t count;

	/* start the repeated digits from function argument, not 0 */
	count = 0;
	for (; repeated < 10; ++repeated)
		if (sieve[generate_number(pattern, len, repeated, non_repeated)])
			++count;

	return count;
}

/* find the smallest prime that forms 8 primes when replacing part of it with
 * the same digit */
int32_t main(void)
{
	int32_t i, j, k;

	/* suppose that the prime to find is composed of 6 digits of which 3 are
	 * the same. Need to form 8 primes, so repeated digit can be even, so
	 * last digit can be repeated (otherwise it would not be prime) */
	uint8_t patterns[10][6] = {
		{1, 1, 1, 0, 0, 0},
		{1, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 1, 1, 1, 0, 0},
		{0, 1, 1, 0, 1, 0},
		{0, 1, 0, 1, 1, 0},
		{0, 0, 1, 1, 1, 0},
		{1, 0, 0, 1, 1, 0},
		{1, 1, 0, 0, 1, 0},
		{1, 0, 1, 0, 1, 0},
	};

	init_sieve();
	for (i = 0; i < 10; ++i)             /* for all possible patterns */
		for (j = 100; j < 1000; ++j) /* for all non-repeated combinations */
			for (k = 0; k <= 2; ++k)
			{
				if (patterns[i][0] == 1 && k == 0)
					continue;
				if (family_length(patterns[i], 6, k, j) == 8)
					goto end;
			}

	end:
	printf("Problem 51: %d\n", generate_number(patterns[i], 6, k, j));

	return 0;
}
