#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int *partition(int *low, int *high) 
{
	int p = *(low + (high - low) / 2);
	while (low <= high) {
		while (*low < p)
			low++;
		while (*high > p)
			high--;
		if (low >= high)
			break;
		swap(low++, high--);
	}
	return high;
}

void quicksort(int *low, int *high)
{
	if (low >= high)
		return;
	int *pivot = partition(low, high);
	quicksort(low, pivot);
	quicksort(pivot + 1, high);
}


main() 
{
	int n;
	scanf("%d\n", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quicksort(arr, arr + n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
