#include <stdio.h>

#define SPACESYMBOL ' '
#define MAXLINE 1000
#define TABSTOP 8

/* fill line from stdin, stops when reaches max */
/* returns length of string */
int get_line(char line[], int max);

/* replace tabs in line, with spacesymbol until next tabstop */
void detab(char new[], char line[], int len, int max, int ts, int spacesymbol);

int main()
{
	int len;
	char line[MAXLINE];
	char new[MAXLINE];

	while((len = get_line(line, MAXLINE)) > 0) {
		detab(new, line, len, MAXLINE, TABSTOP, SPACESYMBOL);
		printf("%s", new);
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

void detab(char new[], char line[], int len, int max, int ts, char spacesymbol)
{
	/* i = original */
	/* j = new */
	int i, j;

	for (i = j = 0; i < len && j < MAXLINE; ++i) {
		if (line[i] == '\t') {
			do {
				new[j] = spacesymbol;
				++j;
			} while (j % TABSTOP != 0);
		}
		else {
			new[j] = line[i];
			++j;
		}
		
	}
}
