#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void push(double);
double pop(void);

int main(int argc, char **argv)
{
	double n;
	double op2;

	/* loop through all arguments */
	while (--argc > 0 && (*++argv)[0] != '\0') {
		if (isdigit(*argv[0])) {
			n = atof(*argv);
			push(n);
			continue;
		}

		switch (*argv[0]) {
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				push(pop() / op2);
				break;
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			default:
				printf("input: invalid operand\n");
				exit(1);
				break;
		}
	}

	printf("result:\n");
	printf("\t[%g]\n", pop());

	return 0;
}

#define STACK_LEN 10000
double stack[STACK_LEN];
int sp = 0;

void push(double x)
{
	if (sp < STACK_LEN)
		stack[sp++] = x;
	else {
		printf("stack: full, cannot push more items\n");
		exit(1);
	}
}

double pop(void)
{
	if (sp > 0)
		return stack[--sp];
	else {
		printf("stack: empty, cannot perform pop()\n");
		exit(1);
	}
}
