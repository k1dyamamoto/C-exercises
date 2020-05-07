#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#define MAXLEN 200

main()
{
	FILE *fp1 = fopen("input1.txt", "r");
	FILE *fp2 = fopen("input2.txt", "r");
	char *line1[MAXLEN], line2[MAXLEN];
	int count = 0;
	while (fgets(line1, MAXLEN, fp1) &&
		fgets(line2, MAXLEN, fp2) &&
		(strcmp(line1, line2) == 0)) {

		count++;
	}
	if (strcmp(line1, line2) == 0)
		printf("Equal files\n");
	else
		printf("lines %d are different\n", count + 1);
}
