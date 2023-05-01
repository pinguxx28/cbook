#include <math.h>
#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
	double val, power;
	int i, sign;
	int exp, exp_sign; /* exponent */

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


	/* skip e */
	if (s[i] == 'e') i++;

	/* get exponent sign */
	exp_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') i++;

	/* get exponent */
	for (exp = 0.0; isdigit(s[i]); i++)
		exp = 10.0 * exp + (s[i] - '0');


	/* return */
	return sign * val / power * pow(10, exp * exp_sign);
}

int main()
{
	printf("%lf\n", atof("123.45e+6"));
}
