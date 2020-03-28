/*
In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?

Author: https://github.com/ravikumark815

Answer: 443839
*/
#include <stdio.h>
#include <stdint.h>

#define TOTAL 200 /* 2 pounds = 200p */

int32_t main(void)
{
	int32_t coins[8]      = {1, 2, 5, 10, 20, 50, 100, 200};
	int64_t ways[TOTAL+1] = {0};
	int32_t i, j;

	ways[0] = 1;
	for (i = 0; i < 8; ++i)
		for (j = coins[i]; j <= TOTAL; ++j)
			ways[j] += ways[j - coins[i]];

	printf("Result: %ld\n", ways[TOTAL]);
	return 0;
}