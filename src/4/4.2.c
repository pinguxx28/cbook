#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
	double val, power;
	int i, sign;

	/* skip whitespace */
	for (i = 0; isspace(s[i]); i++) ;

	/* get sign */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') i++;

	/* get whole int */
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	/* skip dot */
	if (s[i] == '.') i++;

	/* get floating point decimal */
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	/* return */
	return sign * val / power;
}

int main()
{
	printf("%lf, %lf, %lf\n", atof("234.83"), atof("12304.324"), atof("3.0"));
}
