#include <stdio.h>

#define FBRCT "Error: unbalanced \'{\' line:"
#define RBRCT "Error: unbalanced \'(\' line:"
#define SBRCT "Error: unbalanced \'[\' line:"
#define NOERR "No unbalanced parentheses"

main() 
{
        int c, lcnt = 1, flg = 0, dflg = 0, skip = 0;
        int rbrct = 0, sbrct = 0, fbrct = 0;
        int lrcnt, lscnt, lfcnt;
        while ((c = getchar()) != EOF) {
                if (skip)
                        skip = 0;
                else switch (c) {
             	case '\\':
                        if (flg || dflg)
                                skip = 1;
                        break;
                case '\n':
                        lcnt++;
                        break;
                case '\'':
                        if (flg)
                                flg = 0;
                        else if (!flg)
                                flg = 1;
                        break;
                case '\"':
                        if (dflg)
                                dflg = 0;
                        else if (!dflg)
                                dflg = 1;
                        break;
                case '{':
                        if (!flg && !dflg) {
                                fbrct++;
                                lfcnt = lcnt;
                        }
                        break;
                case '[':
                        if (!flg && !dflg) {
                                sbrct++;
                                lscnt = lcnt;
                        }
                        break;
                case '(':
                        if (!flg && !dflg) {
                                rbrct++;
                                lrcnt = lcnt;
                        }
                        break;
                case '}':
                        if (!flg && !dflg) {
                                fbrct--;
                        }
                        break;
                case ']':
                        if (!flg && !dflg) {
                                sbrct--;
                        }
                        break;
                case ')':
                        if (!flg && !dflg) {
                                rbrct--;
                        }
                        break;
                }

                if (fbrct < 0) {
                        printf("%s %d\n", FBRCT, lcnt);
                        return 0;
                } else if (rbrct < 0) {
                        printf("%s %d\n", RBRCT, lcnt);
                        return 0;
                } else if (sbrct < 0) {
                        printf("%s %d\n", SBRCT, lcnt);
                        return 0;
                }
        }

        if (fbrct > 0)
                printf("%s %d\n", FBRCT, lfcnt);
        else if (rbrct > 0)
                printf("%s %d\n", RBRCT, lrcnt);
        else if (sbrct > 0)
                printf("%s %d\n", SBRCT, lscnt);
        else
                printf("%s\n", NOERR);
	
}
