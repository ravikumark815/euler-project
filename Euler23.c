/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

Author: https://github.com/ravikumark815

Answer: 4179871
*/

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int32_t sum_divisors(int32_t n)
{
	int32_t s = 1;
	for (int32_t i = 2; i*i < n+1; ++i)
		if (n%i == 0)
		{
			if (n/i == i)
				s += i;
			else
				s += i + n/i;
		}

	return s;
}

int32_t main()
{
	uint64_t total = 0;
	int32_t SIZE = 28124, i, j;
	int32_t* abundant = (int32_t*)calloc(SIZE, sizeof(int32_t));

	for (i = 2; i < SIZE; ++i)
		abundant[i] = sum_divisors(i) > i ? 1 : 0;

	uint8_t is_sum_abundants;
	for (i = 1; i < SIZE; ++i)
	{
		is_sum_abundants = 0;
		for (j = 1; j < i/2+1; ++j)
			if (abundant[j] && abundant[i-j])
			{
				is_sum_abundants = 1;
				break;
			}

		if (!is_sum_abundants)
			total += i;
	}

	printf("Result: %" PRIu64 "\n", total);
	free(abundant);
	return 0;
}