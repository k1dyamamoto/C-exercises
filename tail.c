#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARG_ERR "wrong arguments\n"
#define DEFAULT_LINES 10

void tail(int lines) {
	char c;
	char *out = malloc(100 * sizeof(char));
	int p = 0, size = 100, l = 0;
	while ((c = getchar()) != EOF) {
		if (p >= size - 1) {
			size *= 2;
			out = realloc(out, size * sizeof(char));
		}
		if (c == '\n')
			l++;
		*(out + p) = c;
		p++;
	}
	*(out + p) = '\0';
	if (l < lines) {
		printf("%s", out);
	} else {
		int j = 0;
		while (j < lines + 1) {
			p--;
			if (*(out + p) == '\n')
				j++;
		}
		printf("%s\n", out + p);
	}
}


main(int argc, char *argv[])
{
	int lines = DEFAULT_LINES;
	if (argc != 3 && argc != 1) {
		printf(ARG_ERR);
		return 0;
	} else if (argc == 3) {
		while (*(++argv) && (*argv)[0] != '-')
			;
		if (*argv) {
			if (strlen(*argv) != 2 || (*argv)[1] != 'n') {
				printf(ARG_ERR);
				return 0;
			}
			argv++;
			int i = 0;
			for (; isdigit((*argv)[i]); i++)
				;
			if (strlen(*argv) != i) {
				printf(ARG_ERR);
				return 0;
			}
			lines = atoi(*argv);
		} else {
			printf(ARG_ERR);
			return 0;
		}
	}
	tail(lines);
}
