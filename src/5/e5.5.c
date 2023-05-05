#include <stdio.h>

void str_n_cpy(char *s, char *t, size_t n)
{
	size_t i;
	for(i = 0; i < n && (*s++ = *t++) != '\0'; i++);
}

int str_n_cmp(char *s, char *t, size_t n)
{
	size_t i = 0;
	for (i = 0; i < n && *s == *t; s++, t++, i++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

void str_n_cat(char *s, char *t, size_t n)
{
	size_t i = 0;
	while (i++ < n && *++s != '\0');
	while (i++ < n && (*s++ = *t++) != '\0');
}

int main()
{
	char a[] = "hello";
	char b[] = "hello";
	printf("%d\n", str_n_cmp(a, b, 8));
}
