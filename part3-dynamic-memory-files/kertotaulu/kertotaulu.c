#include "kertotaulu.h"
#include <stdlib.h> /* For malloc and free. */

Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d) {
  Kertotaulu *kt; /* Declare a pointer to a Kertotaulu structure to hold the
                     multiplication table. */
  uint rows, cols;
  uint i, j, k; /* Loop variables. */

  /* Return NULL if the input parameters are invalid. */
  if (a > b || c > d) {
    return NULL;
  }

  kt = malloc(sizeof(Kertotaulu));
  if (kt == NULL) {
    return NULL;
  }

  kt->a = a;
  kt->b = b;
  kt->c = c;
  kt->d = d;

  rows = d - c + 2;
  cols = b - a + 2;

  /* Allocate memory for the 2D array (array of pointers to rows). */
  kt->kertotaulu = malloc(rows * sizeof(uint *));
  if (kt->kertotaulu == NULL) {
    free(kt);
    return NULL;
  }

  /* Allocate memory for each row (array of uints). */
  for (i = 0; i < rows; ++i) {
    kt->kertotaulu[i] = malloc(cols * sizeof(uint));
    if (kt->kertotaulu[i] == NULL) {
      for (k = 0; k < i; ++k) {
        free(kt->kertotaulu[k]);
      }
      free(kt->kertotaulu);
      free(kt);
      return NULL;
    }
  }

  kt->kertotaulu[0][0] = 0; /* Top-left corner placeholder */

  for (j = 1; j < cols; ++j) {
    kt->kertotaulu[0][j] = a + j - 1; /* Set the column headers. */
  }

  for (i = 1; i < rows; ++i) {
    kt->kertotaulu[i][0] = c + i - 1; /* Set the row headers. */
  }

  for (i = 1; i < rows; ++i) {
    for (j = 1; j < cols; ++j) {
      kt->kertotaulu[i][j] =
          (c + i - 1) *
          (a + j - 1); /* Calculate the multiplication value for each cell. */
    }
  }

  return kt;
}

void tuhoaKertotaulu(Kertotaulu *kt) {
  uint rows = kt->d - kt->c + 2; /* Calculate the number of rows. */
  uint i;                        /* Loop variable. */

  for (i = 0; i < rows; ++i) {
    free(kt->kertotaulu[i]); /* Free each row (array of uints). */
  }
  free(kt->kertotaulu); /* Free the array of row pointers. */
  free(kt);             /* Free the Kertotaulu structure. */
}
