#include <ctype.h>
#include <stdio.h>

int getint(int *pn)
{
	int c, sign;
	while(isspace(c = getchar()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
		return 0;
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getchar();
	if (!isdigit(c))
		return 0;
	for (*pn = 0; isdigit(c); c = getchar())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	return c;
}

main() {
	int a, err;
	err = getint(&a);
	if (err)
		printf("%d\n", a);
	else
		printf("%s\n", "Not a number");
}
