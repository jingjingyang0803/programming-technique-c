/*
EXERCISE: Filtering numbers in an interval
Implement a program that receives as command line parameters two positive
integers, a and b, and possibly one or more further positive integers after
them, and then prints all integers in the interval a , ..., b that are not
evenly divisible by any of the numbers received after a and b. The numbers
should be printed in order from smallest to largest and separated by single
spaces. There must be a line break after the last number.

If zero numbers can be printed, nothing is printed (not even a line break).

Your program may assume that a < b.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b;
  int i, j;
  int first_printed = 0;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s a b [numbers...]\n", argv[0]);
    return 1;
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);

  for (i = a; i <= b; i++) {
    int divisible = 0;
    // Check if i is divisible by any of the numbers provided after a and b
    for (j = 3; j < argc; j++) {
      if (i % atoi(argv[j]) == 0) {
        divisible = 1;
        break;
      }
    }
    // If i is not divisible by any of the provided numbers, print it
    if (!divisible) {
      if (first_printed) {
        printf(" ");
      }
      printf("%d", i);
      first_printed = 1;
    }
  }
  printf("\n");
  return 0;
}
