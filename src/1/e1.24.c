#include <stdio.h>
#include <stdlib.h>

void check_not_end(int variable, const char *name);
void check_counter(int variable, const char *name);

/* syntax checker; checks for syntaxes that are unmatched */
int main()
{
	/* counters for different symbols */
	int braces;        /* {} */
	int brackets;      /* [] */
	int parentheses;   /* () */

	braces = 0;
	brackets = 0;
	parentheses = 0;

	int c;

	while ((c = getchar()) != EOF) {
		switch (c) {
			case '{': ++braces; break;
			case '}': --braces; break;
			case '[': ++brackets; break;
			case ']': --brackets; break;
			case '(': ++parentheses; break;
			case ')': --parentheses; break;
		}
	}

	check_counter(braces, "brace");	
	check_counter(brackets, "bracket");	
	check_counter(parentheses, "parentheses");	

	return 0;
}

void check_not_end(int variable, const char *name)
{
	if (variable < 0) {
		printf("didn't find the start of a %s pair", name);
		exit(1);
	}
}

void check_counter(int variable, const char *name)
{
	if (variable == 0)
		printf("found all %s(s)\n", name);
	else if (variable == 1) /* singular */
		printf("didn't find the end of a %s\n", name);
	else if (variable > 1) /* plural */
		printf("didn't find %d ends of %ss\n", variable, name);
}
