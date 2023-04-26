#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int lim);
void rmv_trail(char line[], int len);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		rmv_trail(line, len);
		printf("%s", line);
	}
}

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

void rmv_trail(char line[], int len)
{
	int i;

	if (line[0] == '\n') {
		line[0] = '\0';
		return;
	}

	for (i = len - 2; line[i] == ' ' || line[i] == '\t'; --i) ;

	line[i + 1] = '\n';
	line[i + 2] = '\0';
}
