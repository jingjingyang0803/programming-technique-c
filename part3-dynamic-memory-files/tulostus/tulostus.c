#include "tulostus.h"

#include <stdio.h>

/* Print the contents of an array of doubles to a file with specified precision.
 */
void tulostaDblTaulu(double *arr, size_t count, const char *arrName, int prec,
                     const char *filename) {
  FILE *f;
  size_t i;

  f = fopen(filename, "w");
  if (f == NULL) {
    return;
  }

  for (i = 0; i < count; i++) {
    fprintf(f, "%s[%lu] = %.*f\n", arrName, (unsigned long)i, prec, arr[i]);
  }

  fclose(f);
}
