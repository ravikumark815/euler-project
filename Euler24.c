/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

Author: https://github.com/ravikumark815

Answer: 2783915460
*/

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Return the factorial of n. */
int32_t factorial(int32_t n)
{
	int32_t p = 1;
	while (n-- > 1) p *= (n+1);
	return p;
}

int32_t main()
{
	int32_t N = 1000000-1, SIZE = 10, digits_left = SIZE, i, d;
	uint64_t answer = 0;
	uint8_t* digits = (uint8_t*)calloc(SIZE, sizeof(uint8_t));

	for (i = 0; i < SIZE; ++i) digits[i] = i;

	for (i = 1; i < SIZE; ++i)
	{
		d = N/factorial(SIZE-i);
		N %= factorial(SIZE-i);
		answer = answer*10 + digits[d];

		for (int32_t j = d; j < digits_left; ++j)
			digits[j] = digits[j+1];
		--digits_left;

		if (N == 0)
			break;
	}

	for (int32_t j = 0; j < digits_left; ++j)
		answer = answer*10 + digits[j];

	printf("Result: %" PRIu64 "\n", answer);
	free(digits);
	return 0;
}