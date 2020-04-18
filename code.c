#include <ctype.h>
#include <stdio.h>

void strncat(char * s, char * t, size_t n)
{
	while (*s++)
		;
	for (s--; n && (*s++ = *t++); --n)
		;
}

void strncpy(char * s, char * t, size_t n)
{
	for (; n && (*s++ = *t++); --n)
		;
	if (n)
		*s++ = '\0';
}

main() {
	char str1[20] = "begin";
	char str2[20] = "end";
	strncpy(str1, str2, 4);
	printf("%s\n", str1);
}
