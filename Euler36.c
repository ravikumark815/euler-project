/*
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

Author: https://github.com/ravikumark815

Answer: 872187
*/

#include <stdio.h>
#include <stdint.h>

#define MAX 1000000

int32_t is_palindrom(int32_t n, int32_t base)
{
	int32_t m, p;

	m = n;
	for (p = 0; n > 0; n /= base)
		p = base * p + n%base;

	return p == m;
}

int32_t main(void)
{
	int i, answer;

	for (i = 1, answer = 0; i < MAX; ++i)
		if (is_palindrom(i, 10) && is_palindrom(i, 2))
			answer += i;

	printf("Result: %d\n", answer);

	return 0;
}