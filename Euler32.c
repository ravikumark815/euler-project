/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

Author: https://github.com/ravikumark815

Answer: 45228
*/

#include <stdio.h>
#include <stdint.h>

int32_t is_pandigital(int32_t mul1, int32_t mul2, int32_t product)
{
	int32_t counter[10] = {0};
	int32_t i;

	for (; mul1 > 0; mul1 /= 10)
		++counter[mul1%10];
	for (; mul2 > 0; mul2 /= 10)
		++counter[mul2%10];
	for (; product > 0; product /= 10)
		++counter[product%10];

	for (i = 1; i < 10; ++i)
		if (counter[i] != 1)
			return 0;

	return counter[0] == 0;
}

int32_t main(void)
{
	int32_t a, b, c, answer = 0;
	int8_t done[10000] = {0};

	for (a = 1; a < 10; ++a)
		for (b = 1000; b < 10000; ++b)
			if (is_pandigital(a, b, c=a*b) && !done[c])
			{
				answer += c;
				done[c] = 1;
			}

	for (a = 10; a < 100; ++a)
		for (b = 100; b < 1000; ++b)
			if (is_pandigital(a, b, c=a*b) && !done[c])
			{
				answer += c;
				done[c] = 1;
			}

	printf("Result: %d\n", answer);
	return 0;
}