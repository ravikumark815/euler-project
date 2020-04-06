/*
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

Author: https://github.com/ravikumark815

Answer: 932718654
*/

#include <stdio.h>
#include <stdint.h>

int32_t is_pandigital(int64_t n)
{
	int8_t digits[10] = {0};

	while (n > 0)
	{
		++digits[n%10];
		n /= 10;
	}

	for (n = 1; n < 10; ++n)
		if (digits[n] != 1)
			return 0;

	return digits[0] == 0;
}

int64_t concatenate_products(int64_t n)
{
	int64_t i, d, product = n;

	for (i = 2; product <= 100000000; ++i)
	{
		d = i * n;
		while (d > 0)
		{
			product = product * 10;
			d /= 10;
		}
		product += i * n;
	}

	return product;
}

int32_t main(void)
{
	int64_t i, p, maximum = 0;

	for (i = 1; i < 100000; ++i)
	{
		p = concatenate_products(i);
		if (is_pandigital(p) && p > maximum)
			maximum = p;
	}

	printf("Problem 38: %ld\n", maximum);
	return 0;
}
