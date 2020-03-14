/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

Answer: 983
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t main()
{
	int32_t MAX = 1000, longest_cycle = 0, answer, remainder, pos, d, i;
	int32_t *already_seen = (int32_t*)calloc(MAX, sizeof(int32_t));

	for (d = MAX; d > 1; --d)
	{
		if (longest_cycle > d-1) break;

		for (i = 0; i < MAX; ++i) already_seen[i] = 0;

		remainder = 1;
		pos = 0;
		while (already_seen[remainder] == 0 && remainder != 0)
		{
			already_seen[remainder] = pos;
			remainder = (remainder*10)%d;
			++pos;
		}

		if (pos - already_seen[remainder] > longest_cycle)
		{
			longest_cycle = pos - already_seen[remainder];
			answer = d;
		}
	}

	printf("Result: %d\n", answer);
	free(already_seen);
	return 0;
}