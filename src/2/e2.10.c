#include <stdio.h>

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

int main()
{
	printf("A to lower = %c\n", lower('A'));
	printf("F to lower = %c\n", lower('F'));
	printf("c to lower = %c\n", lower('c'));
}
