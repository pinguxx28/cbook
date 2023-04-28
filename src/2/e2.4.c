#include <stdio.h>

void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void squeeze_str(char s1[], char s2[])
{
	int i;

	for (i = 0; s2[i] != '\0'; i++) {
		squeeze(s1, s2[i]);
	}
}

int main()
{
	char s1[] = "hello world";
	char s2[] = "lo";

	squeeze_str(s1, s2);
	printf("%s\n", s1);
}
