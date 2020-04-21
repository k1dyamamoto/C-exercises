#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stoi(char * s)
{
	int res = 0;
	while (*s != '\0')
		res = 10 * res + (*s++ - '0');
	return res;
}

main(int argc, char *argv[]) {

	int stack[100], sp = 0;

	while (*(++argv)) {
		if (isdigit((*argv)[0])) {
			stack[sp++] = stoi(*argv);
		} else if ((*argv)[0] == '+') {
			stack[sp - 2] += stack[sp - 1];
			sp--;
		} else if ((*argv)[0] == '-') {
			stack[sp - 2] -= stack[sp - 1];
			sp--;
		} else if ((*argv)[0] == 'x') {
			stack[sp - 2] *= stack[sp - 1];
			sp--;
		} else {
			printf("%s\n", "wrong input");
			return 0;
		}
	}
	printf("%d\n", stack[0]);
}
