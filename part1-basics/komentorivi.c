/*
EXERCISE: Command line parameters
Implement a program that prints all the actual (omit the index 0 parameter, i.e.
the program's call name) command line parameters together with their indexes and
lengths. More precisely, the program should print for each command line
parameter a line of form i: parameter (pituus: x) , where x is the length of the
parameter in question. The parameters are processed according to their indexes
in ascending order, starting from index 1. The example output below should
clarify the expected behavior.
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int i;
  for (i = 1; i < argc; i++) {
    printf("%d: %s (pituus: %lu)\n", i, argv[i], strlen(argv[i]));
  }
  return 0;
}