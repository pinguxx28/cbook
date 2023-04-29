#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

void expand(char s1[], char s2[])
{
	int i, j, c;

	for (i = j = 0; i < MAXLEN-1 && j < MAXLEN-1 && s1[i] != EOF; ++i) {
		if (s1[i] != '-')
			s2[j++] = s1[i];

		if (s1[i+1] == '-')
			for (c = s1[i]+1; c < s1[i+2]; c++)
				s2[j++] = c;
	}
}

int main()
{
	char s1[MAXLEN] = "hello a-e1-4 world a-b-c";
	char s2[MAXLEN];

	expand(s1, s2);
	printf("[%s]\n", s2);
}
