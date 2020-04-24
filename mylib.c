#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int getl(char *str)
{
        char c;
        int len = 0;
        while ((c = getchar()) != '\n' && c != EOF) {
                *(str++) = c;
                len++;
        }
        *str = '\0';
        return len;
}

int getword(char *str)
{
        char c;
        while (isspace(c = getchar()) || c == '\n')
                ;
        int len = 0;
        while (isalpha(c) && c != EOF) {
                *(str++) = c;
                c = getchar();
                len++;
        }
        *str = '\0';
        return len;
}

int getintword(char *str)
{
        char c;
        while (isspace(c = getchar()) || c == '\n')
                ;
        int len = 0;
        int sign = (c == '-') ? 1 : 0;
        if (sign) {
                *(str++) = c;
                len++;
        }
        if (c == '+' || c == '-')
		c = getchar();
        while (isdigit(c) && c != EOF) {
                *(str++) = c;
                c = getchar();
                len++;
        }
        *str = '\0';
        return len;
}
