#include <ctype.h>
#include <stdio.h>

int getfloat(float *pn)
{
	int c, sign, n = 0, pow = 1;
	char str[30];
	while(isspace(c = getchar()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
		return 0;
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getchar();
	if (!isdigit(c))
		return 0;
	for (; isdigit(c); c = getchar())
		str[n++] = c;
	if (c != '.')
		return 0;
	str[n++] = c;
	c = getchar();
	if (!isdigit(c))
		return 0;
	for (; isdigit(c); c = getchar())
		str[n++] = c;
	*pn = 0;
	for (--n; str[n] != '.'; --n) {
		*pn = *pn / 10.0 + (str[n] - '0') / 10.0;
	}
	for (--n; n >= 0; --n) {
		*pn += (str[n] - '0') * pow;
		pow *= 10;
	}
	*pn *= sign;
	return c;
}

main() {
	float a, err;
	err = getfloat(&a);
	if (err)
		printf("%.4f\n", a);
	else
		printf("%s\n", "Not a float number");
}
