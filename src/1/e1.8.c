#include <stdio.h>

main()
{
	int c;
	int blanks;
	int tabs;
	int newlines;

	blanks = 0;
	tabs = 0;
	newlines = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' ) ++blanks;
		if (c == '\t') ++tabs;
		if (c == '\n') ++newlines;
	}

	printf("\' \':\t%2d\n", blanks);
	printf("\'\\t\':\t%2d\n", tabs);
	printf("\'\\n\':\t%2d\n", newlines);
}
