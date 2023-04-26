#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF; ++i) {
		line[i] = c;
		if (c == '\n') break;
	}

	++i;
	line[i] = '\0';

	return i;
}

void reverse(char s[])
{
	int i;
	int len;
	char temp[MAXLINE];

	/* copy to temp */
	for (i = 0; (temp[i] = s[i]) != '\0'; ++i) ;
	len = i-2;

	/* reverse */
	for (i = 0; i <= len; ++i) {
		s[len - i] = temp[i];
	}
}

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}
}
