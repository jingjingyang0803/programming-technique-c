/*
EXERCISE: Transformation

Prints for each actual command line parameter its index, original form, and
transformed form.

Example output:
1: WETO --> otew
2: 3.14159 --> 95141.3
3: Espoo --> OOPSe
 */
#include "muunto.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char transformed[100];
  int i;

  for (i = 1; i < argc; i++) {
    /* Copy the original parameter to transformed */
    strncpy(transformed, argv[i], sizeof(transformed) - 1);

    /* Transform the copied string */
    muunna(transformed);

    printf("%d: %s --> %s\n", i, argv[i], transformed);
  }

  return 0;
}