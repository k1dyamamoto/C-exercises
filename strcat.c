#include <ctype.h>
#include <stdio.h>

void strcat(char * s, char * t)
{
	while (*s++)
		;
	for (s--; *s++ = *t++;)
		;
}

main() {
	char str1[20] = "begin";
	char str2[20] = "end";
	strcat(str1, str2);
	printf("%s\n", str1);
}
