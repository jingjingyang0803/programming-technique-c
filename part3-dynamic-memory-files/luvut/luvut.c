/*
EXERCISE: Input numbers
Write a program that reads numbers from the user until the end of the input. The
program should store the numbers in a dynamically allocated array and print them
in sorted order, along with their sum and average.
*/

#include <stdio.h>
#include <stdlib.h>

/* Comparison function for qsort. */
static int vertaa_dbl(const void *a, const void *b) {
  double x;
  double y;

  x = *(const double *)a;
  y = *(const double *)b;

  if (x < y) {
    return -1;
  }
  if (x > y) {
    return 1;
  }
  return 0;
}

/* Main function. */
int main(void) {
  double *luvut;
  double x;
  size_t s;
  size_t n;
  size_t i;
  double summa;

  s = 2;
  n = 0;
  summa = 0.0;

  luvut = malloc(s * sizeof(double));
  if (luvut == NULL) {
    return 1;
  }

  while (scanf("%lf", &x) == 1) {
    if (n == s) {
      s = 2 * s;
      luvut = realloc(luvut, s * sizeof(double));
      if (luvut == NULL) {
        return 1;
      }
    }

    luvut[n] = x;
    n++;
    summa += x;
  }

  luvut = realloc(luvut, n * sizeof(double));
  if (luvut == NULL && n > 0) {
    return 1;
  }

  qsort(luvut, n, sizeof(double), vertaa_dbl);

  printf("Luettiin %lu lukua:", (unsigned long)n);

  for (i = 0; i < n; i++) {
    printf(" %.3f", luvut[i]);
  }

  printf("\n");
  printf("Summa: %.3f\n", summa);

  if (n > 0) {
    printf("Keskiarvo: %.3f\n", summa / n);
  } else {
    printf("Keskiarvo: %.3f\n", 0.0);
  }

  free(luvut);

  return 0;
}
