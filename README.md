# C-exercises

Exercises (mostly) from Kernigan's book.
#### Basics ####
1. parentheses_errors — finds unbalanced parentheses in a C program (doesn't work with comments yet)
2. hex_to_dec — htoi converts hexadecimal to decimal
3. squeeze — deletes any character in s1 that mathces any character in s2
4. noob_stack — name speaks for itself
5. mylib — header with common input functions
#### Pointers ####
5. getint — writes integer from input or returns 0 if it's not a number
6. getfloat — the floating-point analog of getint (even though it's right to left its precision sucks anyway...)
7. strcat — copies string t to the end of s
8. strncat_strncpy — analogs of <string.h> functions
9. quicksort — name speaks for itself again
10. str_sort — quicksort array of strings
#### Command-line input, more pointers and memory management ####
11. polish_expr — evaluates a reverse Polish expression from the command line (+/-/x allowed)
12. tail — bad analog of UNIX tail, works with -n but memory not optimized
13. qsort — quicksort that now accepts comparator function pointer and reverse flag (-n for numeric input, -r for reverse)
#### Structures, file input ####
14. tree — binary tree that contains words and numbers of their occurrences
15. file_lines — prints out the first unequal lines in input1.txt and input2.txt
