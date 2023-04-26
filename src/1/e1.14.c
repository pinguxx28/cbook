#include <stdio.h>

#define CHARS_LEN 26

main()
{
	int c;
	int n;
	int i, j;
	int low, high;
	int chars[CHARS_LEN];

	low = 10;
	high = 0;

	for (i = 0; i < CHARS_LEN; ++i)
		chars[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
		{
			n = c - 'a';
			++chars[n];
			if (n < low) low = n;
			if (n > high) high = n;
		}
	}

	for (i = low; i <= high; ++i) {
		printf("%c: ", i + 'a');
		for (j = 0; j < chars[i]; ++j)
			putchar('#');
		putchar('\n');
	}
}
