#include <stdio.h>
#include <ctype.h>


void squeeze(char s1[], char s2[])
{
	int i, j, k;
	for (i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; s1[i] != s2[k] && s2[k] != '\0'; k++)
			;
		if (s2[k] == '\0')
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}


main()
{
	char s1[20], s2[20];
	scanf("%s\n%s", s1, s2);
	squeeze(s1, s2);
	printf("%s\n", s1);
}
