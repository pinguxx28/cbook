#include <math.h>
#include <stdio.h>
#include <stdint.h>

#define MAXLINE 1000

size_t get_line(char line[], size_t max);
uint64_t htoi(char line[], size_t len);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		/* printf("%s\n", line); */
		printf("%ld\n", htoi(line, len));
	}
}

size_t get_line(char line[], size_t max)
{
	int i, c;

	for (i = 0; i < max-1; i++) {
		c = getchar();

		if (c == '\n' || c == EOF) break;

		line[i] = c;
	}

	line[i] = '\0';
	return i;
}

uint64_t htoi(char line[], size_t len)
{
	int n, t;
	int i = 0;
	uint64_t sum = 0;

	if (line[0] == '0' && (line[1] == 'x' || line[1] == 'X'))
		i = 2;

	while (i < len) {
		n = 0;

		/* temp */
		t = line[i];

		/* get in lower case */
		if (t >= 'A' && t <= 'F')
			t = t - 'A' + 'a';

		if (t >= '0' && t <= '9') 
			n = t - '0';
		else if (t >= 'a' && t <= 'f')
			n = t - 'a' + 10;
		else
			return -1;

		sum += n * (uint64_t)pow(16, len - i - 1);

		printf("%d ", n);

		i++;
	}

	putchar('\n');

	return sum;
}
