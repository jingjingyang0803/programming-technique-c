/*
This program calls ykkosValit with "input.txt" and "output.txt" as arguments,
and prints the counts of characters read and written to the standard output.
*/

#include "ykkosvalit.h"
#include <stdio.h>

int main(void) {
  UintPari p;

  p = ykkosValit("input.txt", "output.txt");

  printf("Read: %u\n", p.x);
  printf("Written: %u\n", p.y);

  return 0;
}
