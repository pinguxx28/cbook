#include <stdio.h>

/* print Fahrenheit-Celcius table
	for fahr = 0, 20, ..., 300 */
main()
{
	int fahr, celcius;
	int lower, upper, step;

	lower = 0;
	upper = 100;
	step = 10;

	printf("--temp. table\n");

	celcius = lower;
	while (celcius <= upper) {
		fahr = 9 * celcius / 5 + 32;
		printf("%d\t%d\n", celcius, fahr);
		celcius = celcius + step;
	}
}
