#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define PATTERN "ould"

int get_line(char line[], int max);
int strindex(char str[], char pattern[]);

int main()
{
	char line[MAXLINE];
	int found = 0;

	while (get_line(line, MAXLINE) > 0)
		printf("%d\n", strindex(line, PATTERN));

	return found;
}

int get_line(char line[], int max)
{
	int c, i;

	i = 0;
	while (--max > 0 && (c=getchar()) != EOF && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

int strindex(char str[], char pattern[])
{
	int i, j, k;

	for (i = strlen(str)-1; i > 0; i--) {
		for (j=i, k=0; pattern[k] != '\0' && str[j]==pattern[k]; j++, k++) ;

		if (k > 0 && pattern[k] == '\0')
			return i;
	}

	return -1;
}
