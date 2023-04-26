#include <stdio.h>

#define WORD_LENGTHS 10

main()
{
	int c;
	int i, j;
	int longest;
	int low, high;
	int curr_length;
	int word_lengths[WORD_LENGTHS];

	longest = 0;
	low = 10;
	high = 0;
	curr_length = 0;
	for (i = 0; i < WORD_LENGTHS; ++i)
		word_lengths[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n')
		{
			++word_lengths[curr_length];
			if (word_lengths[curr_length] > longest) longest = word_lengths[curr_length];
			if (curr_length < low ) low  = curr_length;
			if (curr_length > high) high = curr_length;
			curr_length = 0;
		}
		else
		{
			++curr_length;
		}
	}

	/* horizontal histogram */
	for (i = low; i <= high; ++i) {
		printf("%d: ", i);
		for (j = 0; j < word_lengths[i]; ++j) {
			putchar('#');
		}
		putchar('\n');
	}

	/* veritcal histogram */
	for (i = longest; i >= 0; --i) {
		for (j = low; j <= high; ++j) {
			if (i == 0) {
				printf("%2d ", j);
				continue;
			}
			if (word_lengths[j] >= i)
				printf("## ");
			else
				printf("   ");
		}
		putchar('\n');
	}
}
