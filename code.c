#include <stdio.h>
#include <ctype.h>


int htoi(char * s)
{
	int i = 0, n = 0;
	if (s[0] == '0')
		i = 2;
	for (;s[i] != '\0'; ++i) {
		if (isdigit(s[i]))
			n = n * 16 + (s[i] - '0');
		else
			n = n * 16 + (tolower(s[i]) - 'a') + 10;
	}
	return n;
}


main()
{
	char s[10];
	scanf("%s", s);
	htoi(s);
	printf("%d\n", htoi(s));
}
