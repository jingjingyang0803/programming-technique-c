/* EXERCISE: Computing square roots
Implement a program that receives as command-line parameters an integer x
followed by one or more numbers, and which prints each number received after x
togehter with its square root using x decimals of precision. The numbers are
processed in the order they were entered on the command line.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, x;
  double num;

  if (argc < 3) {
    printf("Usage: %s x integer [num1 ...]\n", argv[0]);
    return 1;
  }

  /* Parse the precision parameter */
  x = atoi(argv[1]);
  for (i = 2; i < argc; i++) {
    /* Parse the number and print it with its square root */
    num = atof(argv[i]);
    printf("sqrt(%.*f) = %.*f\n", x, num, x, sqrt(num));
  }
  return 0;
}