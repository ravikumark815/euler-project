/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

Author: https://github.com/ravikumark815

Answer: 100
*/

#include <stdio.h>
#include <stdint.h>

int32_t is_curious(int32_t num, int32_t den)
{
	int32_t a, b, c, d;

	a = num/10;
	b = num%10;
	c = den/10;
	d = den%10;

	if (b == 0 && d == 0)
		return 0;

	if (a == c)
		return (float) b / d == (float) num / den;
	else if (a == d)
		return (float) b / c == (float) num / den;
	else if (b == c)
		return (float) a / d == (float) num / den;
	else if (b == d)
		return (float) a / c == (float) num / den;

	return 0;
}

void simplify(int64_t *num, int64_t *den)
{
	int64_t i;

	for (i = *num; i > 1; --i)
		if (*num%i == 0 && *den%i == 0)
		{
			*num /= i;
			*den /= i;
		}
}

int32_t main(void)
{
	int32_t a, b;
	int64_t num, den;
	num = den = 1;

	for (a = 10; a < 100; ++a)
		for (b = a+1; b < 100; ++b)
			if (is_curious(a, b))
			{
				num *= a;
				den *= b;
			}

	simplify(&num, &den);
	printf("Result: %ld\n", den);

	return 0;
}