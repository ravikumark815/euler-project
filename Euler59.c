/*

Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using p059_cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.

Author: https://github.com/ravikumark815

Answer: 129448
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define KEYSIZE 3

int32_t *text;
int32_t size;

/* read_ciphered_text: read the ciphered text from `filename` into the global
 * variable `̣text`. Set the global variable `size` with the text length. */
void read_ciphered_text(char *filename)
{
	char c;
	int32_t i;
	FILE *fp;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Impossible to read the ciphered text.\n");
		size = 0;
	}

	/* Start by counting the number of characters to allocate enough memory.
	 * The file is composed of ascii values separated by commas, so count
	 * the number of commas to get the number of ascii values */
	size = 0;
	while ((c = fgetc(fp)) != EOF)
		if (c == ',')
			++size;
	++size; /* because last ascii value not counted (no ',' after it) */

	/* read each ascii value, store it in text */
	text = calloc(size, sizeof *text);
	fseek(fp, 0, SEEK_SET);    /* move cursor to beginning of file */
	for (i = 0; i < size; ++i)
		fscanf(fp, "%d,", &text[i]);
}

/* decipher: decipher ̣`text` with the `key` (XOR each character with a character
 * of `key`. Cycle through `key` when moving along `text`. Store the result in
 * `deciphered_text`. */
void decipher(int32_t *deciphered_text, char *key, int32_t key_size)
{
	int32_t i;

	for (i = 0; i < size; ++i)
		deciphered_text[i] = text[i] ^ key[i%key_size];
}

/* count_occurrence: return the number of occurrence of `sub` (of size
 * `sub_len`) into `s` (of size `len`). */
int32_t count_occurrence(int32_t *s, int32_t len, int32_t *sub, int32_t sub_len)
{
	int32_t i, j, count;

	count = 0;
	for (i = 0; i < len-sub_len+1; ++i)
	{
		for (j = 0; j < sub_len && s[i+j] == sub[j]; ++j)
			;
		if (j == sub_len)
			++count;
	}
	return count;
}

/* find the best key to decipher text. Sum the ascii values of characters in
 * original text */
int32_t main(void)
{
	int32_t i, j, k, n, *deciphered_text, max_count_occ, answer;
	char key[KEYSIZE], best_key[KEYSIZE];
	int32_t the[] = {'t', 'h', 'e'};

	read_ciphered_text("cipher-e59.txt");
	deciphered_text = calloc(size, sizeof *deciphered_text);

	/* decipher the text with all possible keys (3 letters, lowercase). Keep
	 * the one that produces the maximum number of `the` in the deciphered
	 * text. */
	max_count_occ = 0;
	for (i = 0; i < 26; ++i)
	{
		key[0] = 'a' + i;
		for (j = 0; j < 26; ++j)
		{
			key[1] = 'a' + j;
			for (k = 0; k < 26; ++k)
			{
				key[2] = 'a' + k;
				decipher(deciphered_text, key, KEYSIZE);
				n = count_occurrence(deciphered_text, size,
				                     the, KEYSIZE);

				if (n > max_count_occ)
				{
					memcpy(best_key, key, KEYSIZE);
					max_count_occ = n;
				}
			}
		}
	}

	/* now that the right key is found, decipher and sum ascii values */
	decipher(deciphered_text, best_key, KEYSIZE);
	answer = 0;
	for (i = 0; i < size; ++i)
		answer += deciphered_text[i];

	printf("Problem 59: %d\n", answer);
	return 0;
}