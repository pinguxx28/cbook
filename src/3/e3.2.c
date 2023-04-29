#include <stdio.h>

void escape(char s[], char t[])
{
	/* i is for t and j is for s */
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++, j++) {
		switch (t[i]) {
			case '\n':
				s[j++] = '\\'; 
				s[j] = 'n';
				break;
			case '\t':
				s[j++] = '\\'; 
				s[j] = 't';
				break;
			default:
				s[j] = t[i];
				break;
		}
	}
}

int main()
{
	char t[100] = "hello\tworld\n";
	char s[100];
	escape(s, t);
	printf("[%s]\n", s);
}
