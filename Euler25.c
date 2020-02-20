/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

Author: https://github.com/ravikumark815

Answer: 4782
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void copy(uint8_t* a, uint8_t* b, int32_t size)
{
	for (int32_t i = 0; i < size; ++i) b[i] = a[i];
}

void add(uint8_t* a, uint8_t* b, int32_t size)
{
	int32_t carry = 0, d;
	for (int32_t i = 0; i < size; ++i)
	{
		d = a[i] + b[i] + carry;
		b[i] = d%10;
		carry = d/10;
	}
}

int32_t main()
{
	int32_t SIZE = 1000, n;
	uint8_t *a, *b, *c;
	a = (uint8_t*)calloc(SIZE, sizeof(uint8_t));
	b = (uint8_t*)calloc(SIZE, sizeof(uint8_t));
	c = (uint8_t*)calloc(SIZE, sizeof(uint8_t));

	a[0] = 1;
	b[0] = 1;

	n = 2;
	while (b[SIZE-1] == 0)
	{
		copy(b, c, SIZE);
		add(a, b, SIZE);
		copy(c, a, SIZE);
		++n;
	}

	printf("Result: %d\n", n);

	free(a);
	free(b);
	free(c);
	return 0;
}

