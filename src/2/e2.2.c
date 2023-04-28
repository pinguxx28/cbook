#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAXLINE 80

int main()
{
	int c;
	int i = 0;
	char line[MAXLINE];

	int loop = TRUE;

	while (loop == TRUE) {
		c = getchar();

		if (i >= MAXLINE-1) loop = FALSE;
		if (c == EOF) loop = FALSE;
		if (c == '\n') loop = FALSE;

		line[i] = c;
		i++;
	}
	line[i] = '\0';
	printf("%s", line);
}
