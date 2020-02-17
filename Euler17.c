/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

Author: https://github.com/ravikumark815

Answer: 21124 
*/

#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	uint8_t unit_lengths[] = {
		    3,  3,   5,   4,   4,   3,   5,    5,   4,
		    3,    6,     6,      8,       8,
		      7,      7,       9,       8,        8};

	uint8_t tens_lengths[] = {
		     6,     6,     5,    5,    5,     7,     6,     6};

	int32_t s = 0;
	for (int32_t i = 1; i < 1001; ++i)
	{
		int32_t n = i;
		if (n == 1000)
		{
			s += 11;
			continue;
		}
		if (n%100 == 0)
		{
			s += unit_lengths[n/100-1] + 7;
			continue;
		}
		if (n > 100)
		{
			s += unit_lengths[n/100-1] + 10;
			n %= 100;
		}
		if (n >= 20)
		{
			s += tens_lengths[n/10-2];

			if (n%10 > 0)
				s += unit_lengths[n%10-1];
		}
		if (n < 20)
			s += unit_lengths[n-1];
	}

	printf("Result: %d\n", s);
	return 0;
}