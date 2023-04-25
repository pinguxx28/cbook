#include <stdio.h>

#define MAXLINE 1000
#define ATLEAST 80

int get_line(char line[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF; i++) {
		line[i] = c;
		if (c == '\n') break;
	}

	line[i] = '\0';

	return i;
}

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len >= ATLEAST)
			printf("%s", line);
	}
}
