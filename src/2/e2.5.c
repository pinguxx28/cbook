#include <stdio.h>

int any(char s1[], char s2[])
{
	int i;
	int c;

	for (c = 0; s2[c] != '\0'; c++)
		for (i = 0; s1[i] != '\0'; i++)
			if (s1[i] == s2[c])
				return i;

	return -1;
}

int main()
{
	char s1[] = "hello world";
	char s2[] = "wd";

	printf("%d\n", any(s1, s2));
}
