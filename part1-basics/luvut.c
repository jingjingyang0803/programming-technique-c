/*
EXERCISE: Numbers
Implement a program that prints all positive integers in the interval 1, ...,
100 that are not evenly divisible by two, three or five. You probably want to
use the modulo operator %: an operation of form a % b calculates the remainder
of the division a/b. The numbers should be printed in order from smallest to
largest and they should be separated by single spaces. There must be a line
break after the last number.

The first ten numbers of the expected ouput are shown below. For example the
number 10 is not printed because it is divisible by both 2 and 5, and the number
12 because it is divisible by 3.

1 7 11 13 17 19 23 29 31 37
*/
#include <stdio.h>

int main(void) {
  int first_printed = 0;
  const int MIN = 1;
  const int MAX = 100;

  for (int i = MIN; i <= MAX; i++) {
    if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0) {
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