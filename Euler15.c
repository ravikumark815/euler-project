/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?

Author: https://github.com/ravikumark815

Answer: 137846528820 
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

/* return the binomial coefficient C(n,k) (n choose k) */
uint64_t binomial_coef(uint64_t n, uint64_t k)
{
	uint64_t res = 1;
	if (k > n-k)
		k = n-k;
	for(uint64_t i = 0; i < k; ++i)
	{
		res *= (n-i);
		res /= (i+1);
	}
	return res;
}

int32_t main()
{
	uint64_t answer = binomial_coef(40, 20);
	printf("Problem 15: %" PRIu64 "\n", answer);
	return 0;
}
