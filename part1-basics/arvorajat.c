/*
EXERCISE: Type limits
Implement a program that receives one or more integers as command line
parameters and prints for each number all of the integer types signed char,
unsigned char, short int, unsigned short int and int that would be capable of
storing that number.

Example output:
-293: short int, int
7608: short int, unsigned short int, int
-127: signed char, short int, int
1234567: int
0: signed char, unsigned char, short int, unsigned short int, int
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;

  for (i = 1; i < argc; i++) {
    long num =
        strtol(argv[i], NULL,
               10); /* Convert the command line argument to a long integer */
    printf("%s: ", argv[i]);

    if (num >= SCHAR_MIN && num <= SCHAR_MAX) {
      printf("signed char, ");
    }
    if (num >= 0 && num <= UCHAR_MAX) {
      printf("unsigned char, ");
    }
    if (num >= SHRT_MIN && num <= SHRT_MAX) {
      printf("short int, ");
    }
    if (num >= 0 && num <= USHRT_MAX) {
      printf("unsigned short int, ");
    }
    if (num >= INT_MIN && num <= INT_MAX) {
      printf("int");
    }

    printf("\n");
  }

  return 0;
}