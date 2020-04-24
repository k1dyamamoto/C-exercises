#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#define MAXLEN 200

void swap(char *a[], char *b[])
{
	char *temp = *a;
	*a = *b;
	*b = temp;
}

int numcmp(char *a, char *b)
{
	return (atoi(a) - atoi(b));
}

char **partition(char *low[], char *high[],
		 int (*cmp)(void *, void *), int reverse)
{
	char *p = *(low + (high - low) / 2);
	while (low <= high) {
		while (reverse ? ((*cmp)(p, *low) < 0) : (*cmp)(p, *low) > 0)
			low++;
		while (reverse ? ((*cmp)(*high, p) < 0) : ((*cmp)(*high, p) > 0))
			high--;
		if (low >= high)
			break;
		swap(low++, high--);
	}
	return high;
}

void quicksort(char *low[], char *high[],
	       int (*cmp)(void *, void *), int reverse)
{
	if (low >= high)
		return;
	char **pivot = partition(low, high, cmp, reverse);
	quicksort(low, pivot, cmp, reverse);
	quicksort(pivot + 1, high, cmp, reverse);
}

main(int argc, char *argv[])
{
	int size = 100, len, i = 0, numeric = 0, reverse = 0;
	char temp[MAXLEN];
	char **lineptr = malloc(size * sizeof(char *));
	if (argc > 1) {
		while (*++argv) {
			if (strcmp(*argv, "-n") == 0)
				numeric = 1;
			else if (strcmp(*argv, "-r") == 0)
				reverse = 1;
			else
				printf("Unknown argument %s\n", *argv);
		}
	}
	int (*input)(void *);
	int (*cmp)(void *, void *);
	input = numeric ? getintword : getword;
	cmp = numeric ? numcmp : strcmp;
	while (len = input(temp)) {
		if (size - i <= 1) {
			size *= 2;
			lineptr = realloc(lineptr, size * sizeof(char *));
		}
		*(lineptr + i) = malloc((len + 1) * sizeof(char));
		strcpy(*(lineptr + i), temp);
		i++;
	}
	quicksort(lineptr, lineptr + i - 1, cmp, reverse);
	putchar('\n');
	for (int j = 0; j < i; j++) {
		printf("%s\n", *(lineptr + j));
	}
}
