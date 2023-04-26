#include <stdio.h>

int tocelcius(int fahr);

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d\t%3d\n", fahr, tocelcius(fahr));
}

int tocelcius(int fahr)
{
	return (5.0/9.0) * (fahr-32);
}
