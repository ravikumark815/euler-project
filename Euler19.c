/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Author: https://github.com/ravikumark815

Answer: 171 
*/

#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	int32_t days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int32_t weekday = 2, c = 0, year, month;

	for (year = 1901; year < 2001; ++year)
		for (month = 0; month < 12; ++month)
		{
			if (year%4 == 0 && month == 1)
				weekday += 29;
			else
				weekday += days[month];

			weekday %= 7;
			if (weekday == 0)
				++c;
		}

	printf("Result: %d\n", c);
	return 0;
}