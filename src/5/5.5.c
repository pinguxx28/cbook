#include <stdio.h>

void str_cpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0');
}

int main()
{
	char a[] = "hello";
	char b[] = "apple";
	str_cpy(a, b);
	printf("%s\n", a);
}
