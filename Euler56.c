/*
A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?

Author: https://github.com/ravikumark815

Answer: 972
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* 100^100 has 200 digits. Since a^b < 100^100 for a,b in 1..100, the maximum
 * number of digits in a^b is 200 */
#define LEN 200

/* multiply_and_sum: multiply n by m where each digit of n is stored in a
 * different cell of array digits[]. n is stored in reverse order (1234 is
 * stored as [4,3,2,1]). Compute the sum of all digits as it processes the array
 */
int32_t multiply_and_sum(int32_t *digits, int32_t m)
{
	int32_t i, carry, sum;

	carry = sum = 0;
	for (i = 0; i < LEN; ++i)
	{
		carry = digits[i] * m + carry;
		digits[i] = carry%10;
		sum += digits[i];
		carry /= 10;
	}

	return sum;
}

/* sum the digits of each product a^b, print the largest sum */
int32_t main(void)
{
	int32_t a, b, tmp, max_sum, *digits;

	digits = calloc(LEN, sizeof *digits);
	max_sum = 0;

	for (a = 2; a < 100; ++a)
	{
		/* reset array */
		memset(digits, 0, LEN * sizeof *digits);
		digits[0] = 1;

		for (b = 1; b < 100; ++b)
		{
			tmp = multiply_and_sum(digits, a);
			if (tmp > max_sum)
				max_sum = tmp;
		}
	}

	printf("Problem 56: %d\n", max_sum);
	return 0;
}