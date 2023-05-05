#include <stdio.h>

size_t str_len(char *str)
{
	int i;
	for (i = 0; *str++ != '\0'; i++);
	return i;
}

int str_end(char *s, char *t)
{
	size_t sl = str_len(s);
	size_t tl = str_len(t);

	s += sl;
	t += tl;

	while (tl && (*s-- == *t--)) --tl;

	if (tl)
		return 0;
	else
		return 1;
}

int main()
{
	char a[] = "hello";
	char b[] = "lo";
	printf("%d\n", str_end(a, b));
	return 0;
}
