/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.

Author: https://github.com/ravikumark815

Answer: 16695334890
*/
#include <stdio.h>
#include <stdint.h>

int32_t main(void)
{
	/* d4 d5 d6 is divisible by 5 => d6 is 0 or 5
	 *
	 * If d6 is 0, then d6 d7 d8 can be 011, 022, 033 ... 099 (must be
	 * divisible by 11) => impossible because number is pandigital (so no
	 * digit is repeated). d6 must be 5.
	 *
	 * The possibilites for d6 d7 d8 are: 506, 517, 528, ..., 594. If it's
	 * 506 then d9 is 5 (because 0 6 d9 must be divisible by 13) =>
	 * impossible because 5 would be repeated. If it's 517, then there is no
	 * digit such that 1 7 d9 is divisible by 13, so impossible. If it's
	 * 528, then d9 is 6 (286 is divisible by 13). With the same reasoning,
	 * the only choices for d6 d7 d8 d9 are: 5286, 5390, 5728, 5832.
	 *
	 * With the same reasoning for d10, 5832 is impossible (that would give
	 * d10 = 3, and 3 would be reapeated). The choices for d6-d10 are then:
	 * 52867, 53901 and 57289.
	 *
	 * To find d5, we need to find digits X such that X52 or X53 or X57 are
	 * multiples of 7. That gives 952, 553 and 357. Because of repeated 5,
	 * the only choices for d5-d10 are then 952867 and 357289.
	 *
	 * For the first choice, the digits left are: 0, 1, 3 and 4. Since d2 d3
	 * d4 must be divisible by 2, d4 can only be 0 or 4. d4 cannot be 4,
	 * because d3+d4+d5 must be divisible by 3 and given that d5=9, there is
	 * no right choice for d3 to fulfill this condition. So d4 is 0, d3 is 3
	 * (because of divisibility by 3 condition). So d1 d2 can be 14 or 41.
	 * That gives {14, 41}30952867.
	 *
	 * For the second case, the digits left are: 0, 1, 4 and 6. For the same
	 * reasons, d4 can only be 0 or 4 or 6, and also for the same reasons
	 * (divisibility by 3 for d3 d4 d5) it cannot be 4. So either d4 is 0
	 * (and d3 is 6) or d4 is 6 (and d3 is 0). For both cases, d1 d2 can
	 * either be 14 or 41. That gives {14, 41}{60, 06}357289.
	 */
	int64_t answer = 1430952867 + 4130952867 +
	                 1460357289 + 4160357289 +
			 1406357289 + 4106357289;

	printf("Problem 43: %ld\n", answer);
	return 0;
}