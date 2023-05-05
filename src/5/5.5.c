#include <stdio.h>

void str_cpy(char *s, char *t)
{
	while (*s++ = *t++);
}

int str_cmp(char *s, char *t)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int main()
{
	char a[] = "hello";
	char b[] = "apple";
	str_cpy(a, b);
	printf("%s\n", a);
	printf("%d\n", str_cmp(a, b));
}
