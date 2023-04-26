#include <stdio.h>

#define SPACESYMBOL ' '
#define MAXLINE 1000
#define TABSTOP 8

/* fill line from stdin, stops when reaches max */
/* returns length of string */
int get_line(char line[], int max);

/* replace tabs in line, with spacesymbol until next tabstop */
void entab(char new[], char line[], int len, int max, int ts, char spacesymbol);

int main()
{
	int len;
	char line[MAXLINE];
	char new[MAXLINE];

	while((len = get_line(line, MAXLINE)) > 0) {
		entab(new, line, len, MAXLINE, TABSTOP, SPACESYMBOL);
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

void entab(char new[], char line[], int len, int max, int ts, char spacesymbol)
{
	/* i is pointer to 'line' */
	/* j is pointer to 'new' */
	/* s is to loop spaces */
	/* spaces is the amount of spaces to insert */
	int i, j;
	int s, spaces;

	for (i = j = 0; i < len && j < MAXLINE;) {
		spaces = 0;

		/* normal characters */
		if (line[i] != ' ') {
			new[j] = line[i];
			++j; ++i;
			continue;
		}

		while (line[i] == ' ') {
			++i;
			++spaces;

			if (i % ts == 0) {
				spaces = 0;
				new[j] = '\t';
				++j;
			}
		}

		for (s = 0; s < spaces; ++s) {
			new[j] = ' ';
			++j;
		}
	}
	++j;
	new[j] = '\0';
}
