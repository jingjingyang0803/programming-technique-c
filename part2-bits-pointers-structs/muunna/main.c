#include "muunna.h"
#include <math.h>
#include <stdio.h>

double treble(double x) { return 3 * x; }

int main(void) {
  int i = 0;
  double dt[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
  muunnaTaulu(10, dt, treble);
  for (i = 0; i < 10; ++i) {
    printf(" %.1f", dt[i]); /* Ouput with 1 decimal of precision. */
  }
  printf("\n");
  muunnaTaulu(10, dt,
              sqrt); /* sqrt is a square root function provided by math.h. */
  for (i = 0; i < 10; ++i) {
    printf(" %.2f", dt[i]); /* Ouput with 2 decimals of precision. */
  }
  printf("\n");
  return 0;
}
