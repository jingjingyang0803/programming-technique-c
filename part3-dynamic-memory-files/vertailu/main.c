#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Compares double values in respect of a descending sorting order. */
static int dblLaskevaVrt(const void *a, const void *b) {
  const double *x = a; /* The function assumes that a and b */
  const double *y = b; /* point to double values. */
  return (*x > *y) ? -1 : ((*x < *y) ? 1 : 0); /* Compare the pointed values. */
} /* Note how the comparison is done in "opposite" order to reflect descending
     order. */

static int mjKasvavaVrt(const void *a, const void *b) {
  char *const *x =
      a; /* char * const * because the function assumes a and b to */
  char *const *y =
      b; /* point to const pointers that point to char * strings! */
  return strcmp(*x,
                *y); /* Use strcmp to compare the indirectly pointed strings. */
}

int main(int argc, char *argv[]) {
  int i = 0;
  double dt[5] = {-345.55, 123.45, -729.61, 3.14, 95.70};
  qsort(dt, 5, sizeof(double), dblLaskevaVrt);
  qsort(argv + 1, argc - 1, sizeof(char *), mjKasvavaVrt);
  for (i = 0; i < 5; ++i) {
    printf(" %.2f", dt[i]);
  }
  printf("\n");
  for (i = 1; i < argc; ++i) {
    printf(" %s", argv[i]);
  }
  printf("\n");
  return 0;
}
