#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 80
#define MAXLINES 5000
char *lines[MAXLINES];
int lines_p = 0;

int get_line(char *line, int max)
{
	int c, i;

	for (i = 0; i < max && (c = getchar()) != EOF; i++) {
		if (c == '\n') break;
		line[i] = c;
	}

	line[i] = '\0';

	return i;
}

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int n = 10;
	int i, len;

	assert(argc <= 2);
	if (argc == 2) {
		assert(argv[1][0] == '-');
		n = -1 * atoi(argv[1]);
	}

	while ((len = get_line(line, MAXLINE)) > 0) {
		lines[lines_p++] = line;
	}

	printf("------\n\n");
	printf("%s\n", lines[lines_p--]);

	/* lines_p -= n; */
	/* for (i = 0; i < n; i++) */
	/* 	printf("[%s]\n", lines[lines_p + i]); */


	return 0;
}
