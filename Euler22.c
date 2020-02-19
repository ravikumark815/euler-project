/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

Author: https://github.com/ravikumark815

Answer: 871198282
*/

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VOCAB_SIZE 6000

/* Function used by qsort to sort alphabetically names. */
int32_t cmp_names(const void *a, const void *b)
{
	return strcmp(*(const char **) a, *(const char **) b);
}

int32_t main()
{
	/* Open file. */
	FILE *file = fopen("names.txt", "r");
	if (file == NULL)
	{
		printf("[ERROR] Unable to open names.txt, exiting.\n");
		return 1;
	}

	/* Parse and store names. */
	uint8_t **names, MAX_LENGTH = 50, l = 0;
	int32_t n_words = 0, c;
	names    = (uint8_t**)calloc(MAX_VOCAB_SIZE, sizeof(uint8_t*));
	names[0] = (uint8_t*)calloc(MAX_LENGTH, sizeof(uint8_t));

	while ((c = getc(file)) != EOF)
	{
		if (c == ',') /* word separator */
		{
			l = 0;
			names[++n_words] = (uint8_t*)calloc(MAX_LENGTH, sizeof(uint8_t));
		}

		else if (c == '"')
			continue;
		else
			names[n_words][l++] = c;
	}

	/* No ',' after last word, but counter needs to be incremented. */
	++n_words;

	/* Sort words alphabetically. */
	qsort(names, n_words, sizeof(const uint8_t*), cmp_names);

	/* Compute total sum of scores of all names. */
	uint64_t total = 0, score;
	for (int32_t pos = 0; pos < n_words; ++pos)
	{
		score = 0;
		for (int32_t i = 0; names[pos][i] != 0; ++i)
			score += names[pos][i] - 'A' + 1;

		total += score * (pos+1);
	}

	printf("Result: %" PRIu64 "\n", total);

	/* Clear allocated memory. */
	for (int32_t i = 0; i < n_words; ++i) free(names[i]);
	free(names);
	fclose(file);

	return 0;
}