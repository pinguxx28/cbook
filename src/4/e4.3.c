#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP   100
#define MAXVAL  100 
#define BUFSIZE 100
#define NUMBER  '0'

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("result: %.8g\n", pop());
			break;
		default:
			printf("error: uknown command%s\n", s);
			break;
		}
	}

	return 0;
}


int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int bufp = 0;
char buf[BUFSIZE];

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many character\n");
	else
		buf[bufp++] = c;
}

int getop(char s[])
{
	int i = 0, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') ;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	if (c == '-') {
		int next = getch();
		if (!isdigit(next) && next != '.')
			return next;

		s[i] = c;
		ungetch(c = next);
	}
	else
		c = getch();

	if (isdigit(c)) /* collect int part */
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i+1] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}


