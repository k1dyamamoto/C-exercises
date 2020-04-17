#include <stdio.h>
#include <ctype.h>

#define MAXVAL 100
#define stype double

int sp = 0;
stype val[MAXVAL];

void push(stype x)
{
	if (sp < MAXVAL)
		val[sp++] = x;
	else
		printf("%s\n", "error: stack full")
}

stype pop(void)
{
	if (sp)
		return val[--sp];
	else {
		printf("%s\n", "error: stack empty");
		return 0;
	}
}

stype top(void)
{
	if (sp)
		return val[sp - 1];
	else
		return 0;

}

void duplicate(stype arr[], int n)
{
	for (int i = 0; i < sp || i < n; i++)
		arr[i] = sp[i];
}

void swap(void)
{
	if (sp > 1) {
		stype temp = top();
		val[sp - 1] = val[sp - 2];
	} else {
		printf("%s\n", "error: not enough elements");
	}
}

void clear(void)
{
	for (int i = 0; i < sp; val[i++] = 0)
		;
	sp = 0;
}
