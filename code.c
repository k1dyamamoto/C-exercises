#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 100

void swap(char *a[], char *b[])
{
	char *temp = *a;
	*a = *b;
	*b = temp;
}


char **partition(char *low[], char *high[])
{
	char *p = *(low + (high - low) / 2);
	while (low <= high) {
		while (strcmp(p, *low) > 0)
			low++;
		while (strcmp(*high, p) > 0)
			high--;
		if (low >= high)
			break;
		swap(low++, high--);
	}
	return high;
}

void quicksort(char *low[], char *high[])
{
	if (low >= high)
		return;
	char **pivot = partition(low, high);
	quicksort(low, pivot);
	quicksort(pivot + 1, high);
}


main() {
	char *s1 = "abc";
	char *s2 = "zdccba";
	char *s3 = "abcdef";
	char *s4 = "zbk";
	char *s5 = "hfff";
	char *s6 = "a";
	char *arr[6] = {s1, s2, s3, s4, s5, s6};
	quicksort(arr, arr+5);
	for (int i = 0; i < 6; ++i)
		printf("%s\n", arr[i]);
}
