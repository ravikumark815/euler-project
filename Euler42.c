/*
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

Author: https://github.com/ravikumark815

Answer: 162
*/
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAXLEN 100

/* word_value: return the sum of each letter value in string s */
int32_t word_value(char *s)
{
	int32_t val;

	for (val = 0; *s != '\0'; ++s)
		val += (*s - 'A' + 1);
	return val;
}

/* is_triangular: return 1 if n is a triangular number (it can be written as
 * m(m+1) / 2 ) */
int32_t is_triangular(int32_t n)
{
	int32_t m = (int32_t) sqrt(n*2);
	return m*(m+1) / 2 == n;
}

/* read_word: read a word from a file that is like "A","ABILITY","ABLE"... */
int32_t read_word(FILE *fp, char *dest)
{
	int32_t c;

	/* skip quotes and comma */
	while ((c = fgetc(fp)) != EOF && !isupper(c))
		;
	*dest++ = c;

	/* read letters until it finds a comma or a quote */
	while ((c = fgetc(fp)) != EOF && isupper(c))
		*dest++ = c;
	*dest = '\0';

	return c;
}

int32_t main(void)
{
	FILE *fp;
	char word[MAXLEN];
	int32_t answer = 0;

	fp = fopen("words-e42.txt", "r");
	while (read_word(fp, word) != EOF)
		if (is_triangular(word_value(word)))
			++answer;

	printf("Problem 42: %d\n", answer);
	return 0;
}