/*


Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?


Author: https://github.com/ravikumark815

Answer: 26241
*/
#include <stdio.h>
#include <stdint.h>

#define N 1000000 /* 10**6 */

int8_t sieve[N];

/* init_sieve: initialize the array to test primality of a number (Eratosthene
 * sieve) */
void init_sieve(void)
{
	int32_t i, j;

	/* at first, suppose that every numbers are prime, except 0 and 1 */
	for (i = 0; i < N; ++i)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;

	/* when a prime is found, mark all its multiples as non-prime */
	for (i = 2; i < N; ++i)
		if (sieve[i])
			for (j = 2*i; j < N; j += i)
				sieve[j] = 0;
}

/* is_prime: return 1 if n is prime, 0 otherwise */
int32_t is_prime(int64_t n)
{
	int64_t p;

	/* use the sieve array if n is small enough to know its primality
	 * directly */
	if (n < N)
		return sieve[n];

	/* n is not prime if there exists p <= sqrt(n) such that p divides n */
	for (p = 2; p*p <= n; ++p)
		if (sieve[p] && n%p == 0)
			return 0;
	return 1;
}

/* n_primes_corners: return the number of primes among the 4 corners if the
 * numbers are written is spiral and the square has a side length of len */
int64_t n_primes_corners(int64_t len)
{
	int64_t i, n;

	/* bottom right corner is n=len^2. Other corners are obtained by
	 * successively subtracting (len-1) */
	i = 0;
	n = len*len;     /* bottom right, obviously non-prime */

	n -= (len-1);    /* bottom left */
	if (is_prime(n))
		++i;

	n -= (len-1);    /* top right */
	if (is_prime(n))
		++i;

	n -= (len-1);    /* top left */
	if (is_prime(n))
		++i;

	return i;
}

/* find the len of square required so the ratio between prime and non-prime
 * numbers on the diagional is below 10% */
int32_t main(void)
{
	int32_t i, total_primes = 0;
	float ratio;

	init_sieve();
	for (i = 3; ; i += 2)
	{
		total_primes += n_primes_corners(i);
		ratio = total_primes / (float) (2*i - 1);
		if (ratio < 0.10f)
			break;
	}

	printf("Problem 58: %d\n", i);
	return 0;
}
