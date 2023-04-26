#include <stdio.h>

#define MAXLEN 1000

#define ON 0
#define OFF 1

int main()
{
	int c;  /* curr char */
	int lc; /* last char */

	int cmt_mode; /* inside a comment */
	int str_mode; /* inside a string */

	lc = 0;
	cmt_mode = str_mode = OFF;

	while ((c = getchar()) != EOF) {
		/* string mode */
		if (c == '\"' && cmt_mode == OFF) {
			if (str_mode == ON) str_mode = OFF;
			else if (str_mode == OFF) str_mode = ON;
		}

		/* comment mode */
		if (lc == '/' && c == '*' && str_mode == OFF) {
			cmt_mode = ON;
			lc = c;
			printf("\b \b");
			continue;
		}
		if (lc == '*' && c == '/' && str_mode == OFF && cmt_mode == ON) {
			cmt_mode = OFF;
			lc = c;
			continue;
		}

		lc = c;
		if (cmt_mode == OFF) {
			putchar(c);
		}
	}
}
