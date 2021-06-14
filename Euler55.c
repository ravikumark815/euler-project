/*
If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.

Author: https://github.com/ravikumark815

Answer: 249
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SIZE 40  /* 50 iterations will use numbers with at most 40 digits */
#define N 10000  /* count the Lychrel numbers from 1 to 10'000 */

/* is_palindrom: return 1 if array ar is palindromic, 0 otherwise */
int32_t is_palindrom(uint8_t *ar, int32_t len)
{
	int32_t i;
	for (i = 0; i <= len/2; ++i)
		if (ar[i] != ar[len-1-i])
			return 0;
	return 1;
}

/* sum_reverse: compute n + reverse(n) where digits of n are stored in ar[].
 * Store result in sum[]. Return the number of digits in sum[] */
int32_t sum_reverse(uint8_t *ar, uint8_t *sum, int32_t len)
{
	int32_t carry, i;

	for (i = 0, carry = 0; i < len; ++i)
	{
		carry += ar[i] + ar[len-1 - i];
		sum[i] = carry%10;
		carry /= 10;
	}

	while (carry > 0)
	{
		sum[i++] = carry%10;
		carry /= 10;
	}

	return i;
}

/* is_lychrel: return 1 if n is a Lychrel number (summing n and reverse(n) gives
 * a palindromic number) or n+reverse(n) is a Lychrel number. Return 0 otherwise
 * (not a Lychrel number, even after 50 iterations). */
int32_t is_lychrel(int32_t n)
{
	uint8_t digits[SIZE] = {0}, sum[SIZE] = {0};
	int32_t n_iter, i;

	/* store digits of n into an array */
	for (i = 0; n > 0; ++i)
	{
		digits[i]  = n%10;
		n /= 10;
	}

	for (n_iter = 0; n_iter < 50; ++n_iter)
	{
		i = sum_reverse(digits, sum, i);

		if (is_palindrom(sum, i))
			return 1;

		memcpy(digits, sum, i * sizeof(uint8_t));
		memset(sum, 0, i * sizeof(uint8_t));
	}

	return 0;
}

/* print the number of non-Lychrel numbers between 1..10'000 */
int32_t main(void)
{
	int32_t i, answer = 0;

	for (i = 0; i < N; ++i)
		if (!is_lychrel(i))
			++answer;

	printf("Problem 55: %d\n", answer);
	return 0;
}