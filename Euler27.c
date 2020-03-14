/*
Euler discovered the remarkable quadratic formula:

n^2+n+41
It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.

The incredible formula n^2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n2+an+b, where |a|<1000 and |b|≤1000

where |n| is the modulus/absolute value of n
e.g. |11|=11 and |−4|=4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.



Answer: -59231
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t main()
{
	uint64_t N = 1000000, i, j;
	uint8_t *sieve = (uint8_t*)calloc(N, sizeof(uint8_t));
	for (i = 0; i < N; ++i) sieve[i] = 1;

	for (i = 2; i < N; ++i)
		if (sieve[i-1])
			for (j = 2*i; j < N+1; j += i)
				sieve[j-1] = 0;

	int32_t MAX = 1000, max_num_primes = 0, product, a, b, n, tmp;
	for (a = -MAX+1; a < MAX; ++a)
		for (b = -MAX+1; b < MAX; ++b)
		{
			n = 0;
			tmp = b;

			if (tmp < 0) tmp *= -1;

			while (sieve[tmp-1])
			{
				++n;
				tmp = n*n + a*n + b;
				if (tmp < 0) tmp *= -1;
			}

			if (n > max_num_primes)
			{
				max_num_primes = n;
				product = a*b;
			}
		}

	printf("Result: %d\n", product);

	free(sieve);
	return 0;
}
