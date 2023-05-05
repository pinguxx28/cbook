#include <stdio.h>

/* assumes there is space in both strings */
void str_cat(char *s, char *t)
{
	while (*++s != '\0');
	while ((*s++ = *t++) != '\0');
}

int main()
{
	char a[15] = "hello";
	char *b = "world";
	str_cat(a, b);
	printf("[%s]\n", a);
}
