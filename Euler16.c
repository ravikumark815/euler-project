/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Author: https://github.com/ravikumark815

Answer: 1366 
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void mutiply(uint8_t* ar, int32_t size, int32_t n)
{
	int32_t carry = 0, s;
	for (int32_t i = 0; i < size; ++i)
	{
		s = ar[i] * n + carry;
		ar[i] = s%10;
		carry = s/10;
	}
}

int32_t main()
{
	int32_t size = 320, power = 1000;
	uint64_t sum = 0;
	uint8_t* number = (uint8_t*) calloc(size, sizeof(uint8_t));
	number[0] = 1;

	while (power--)
		mutiply(number, size, 2);

	while(size--)
		sum += number[size-1];

	printf("Result: %" PRIu64 "\n", sum);
	free(number);
	return 0;
}