#include <stdio.h>

#define MAXLINE 1000
#define COL 20

/* fill line from stdin, stops when reaches max */
/* returns length of string */
int get_line(char line[], int max);

/* replace tabs in line, with spacesymbol until next tabstop */
void fold(char line[], int max, int col);

int main()
{
	int len;
	char line[MAXLINE];

	while((len = get_line(line, MAXLINE)) > 0) {
		fold(line, MAXLINE, COL);
	}
}

int get_line(char line[], int max)
{
	int i, c;

	for (i = 0; i < max-1 && (c = getchar()) != EOF; ++i) {
		line[i] = c;

		if (c == '\n') {
			++i;
			break;
		}
	}

	line[i] = '\0';

	return i;
}

void fold(char line[], int max, int col)
{
	int i;
	int j;
	int ls;
	int b; 

	for (i = 0; i < max;) {
		/* find last space */
		for (j = i; j < i + col; ++j)
			if (line[j] == ' ')
				ls = j;
			else if (line[j] == '\n' || line[j] == '\0') {
				ls = j;
				b = 1;
			}

		line[ls] = '\n';
		i = ls + 1;

		if (b == 1) break;
	}


	printf("%s", line);
}
