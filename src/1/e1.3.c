#include <stdio.h>

/* print Fahrenheit-Celcius table
	for fahr = 0, 20, ..., 300 */
main()
{
	int fahr, celcius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("--temp. table\n");

	fahr = lower;
	while (fahr <= upper) {
		celcius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celcius);
		fahr = fahr + step;
	}
}
