#include "kertotaulu.h"
#include <stdlib.h> /* For malloc and free. */

Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d) {
  Kertotaulu *kt = malloc(sizeof(Kertotaulu)); /* Allocate memory for a
                                      Kertotaulu structure. */
  uint rows, cols;                             /* Number of rows and columns. */
  uint i, j, k;                                /* Loop variables. */

  if (a > b || c > d) {
    return NULL; /* Return NULL if the input parameters are invalid. */
  }

  if (kt != NULL) {
    kt->a = a;        /* Set the starting value for the columns. */
    kt->b = b;        /* Set the ending value for the columns. */
    kt->c = c;        /* Set the starting value for the rows. */
    kt->d = d;        /* Set the ending value for the rows. */
    rows = d - c + 1; /* Calculate the number of rows. */
    cols = b - a + 1; /* Calculate the number of columns. */
    kt->kertotaulu = malloc(rows * sizeof(uint *)); /* Allocate memory for the
                                      array of row pointers. */
    if (kt->kertotaulu != NULL) {
      for (i = 0; i < rows; ++i) {
        kt->kertotaulu[i] = malloc(cols * sizeof(uint)); /* Allocate memory for
                                    each row (array of uints). */
        if (kt->kertotaulu[i] != NULL) {
          for (j = 0; j < cols; ++j) {
            kt->kertotaulu[i][j] = (c + i) * (a + j); /* Calculate the value for
                                    each cell in the multiplication table. */
          }
        } else {
          /* If memory allocation fails, free previously allocated memory and
           * return NULL. */
          for (k = 0; k < i; ++k) {
            free(kt->kertotaulu[k]); /* Free previously allocated rows. */
          }
          free(kt->kertotaulu); /* Free the array of row pointers. */
          free(kt);             /* Free the Kertotaulu structure. */
          return NULL;          /* Return NULL to indicate failure. */
        }
      }
    } else {
      /* If memory allocation fails, free previously allocated memory and
       * return NULL. */
      free(kt);    /* Free the Kertotaulu structure. */
      return NULL; /* Return NULL to indicate failure. */
    }
  } else {
    return NULL; /* Return NULL if memory allocation for Kertotaulu structure
                    fails. */
  }

  return kt; /* Return the created Kertotaulu structure. */
}

void tuhoaKertotaulu(Kertotaulu *kt) {
  uint rows = kt->d - kt->c + 1; /* Calculate the number of rows. */
  uint i;                        /* Loop variable. */

  for (i = 0; i < rows; ++i) {
    free(kt->kertotaulu[i]); /* Free each row (array of uints). */
  }
  free(kt->kertotaulu); /* Free the array of row pointers. */
  free(kt);             /* Free the Kertotaulu structure. */
}
