/*
Problem 14 - Collatz sequence

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Author: https://github.com/ravikumark815

Answer: 837799

*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t main()
{
	uint64_t N = 1000000, longest = 0, answer, n, i, s;
	uint64_t *lengths = (uint64_t*) calloc(N, sizeof(uint64_t));
	for (i = 0; i < N; ++i)
		lengths[i] = 0;

	for (i = 1; i < N+1; ++i)
	{
		n = i; 
		s = 1; 

		while (n > 1)
		{
			if (n < N && lengths[n-1] > 0)
			{
				s += lengths[n-1] - 1;
				break;
			}

			if (n&1)
				n = 3*n + 1;
			else
				n >>= 1;
			++s;
		}

		lengths[i-1] = s;

		if (s > longest)
		{
			longest = s;
			answer = i;
		}
	}

	printf("Problem 14: %" PRIu64 "\n", answer);
	free(lengths);
	return 0;
}
