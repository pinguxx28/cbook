#include <stdio.h>

static char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

#define LEAP(year) ((year) % 4 == 0 && (year)%100 != 0 || (year)%400 == 0)

/* day of year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int m;
	int leap = LEAP(year); 

	for (m = 1; m < month; m++)
		day += daytab[leap][m];

	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int m;
	int leap = LEAP(year);

	for (m = 1; yearday > daytab[leap][m]; m++)
		yearday -= daytab[leap][m];

	*pmonth = m;
	*pday = yearday;
}

int main(void)
{
	int doy = day_of_year(1988, 10, 13);
	int month, day;

	printf("%d\n", doy);

	month_day(1988, doy, &month, &day);
	printf("%d, %d\n", month, day);

	
}
