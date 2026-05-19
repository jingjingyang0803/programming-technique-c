#include "mjonot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* The comparison function strcmp, the length function strlen. */

int pituusjarj(const char *a, const char *b) {
  return (strlen(a) < strlen(b)); /* Is a shorter than b? */
}

int aakkosjarj(
    const char *a,
    const char *b) { /* strcmp compares alphabetical string order. Given strings
                        a and b, strcmp returns a negative int value, if a < b,
                        zero, if a == b, and a positive int value, if a > b. */
  return (strcmp(a, b) < 0); /* Is a alphabetically smaller than b? */
}

int main(int argc, char *argv[]) {
  size_t lkm = argc - 1;
  char **aakkoset = jarjesta_mjt(&argv[1], lkm, aakkosjarj);
  char **pituudet = jarjesta_mjt(&argv[1], lkm, pituusjarj);
  size_t i = 0;
  /* The original order */
  printf("Alkuperäinen järjestys:\n");
  for (i = 1; i <= lkm; ++i) {
    printf(" %s\n", argv[i]);
  }
  /* Sorted in ascending order by string length */
  printf("Pituusjärjestys:\n");
  for (i = 0; i < lkm; ++i) {
    printf(" %s\n", pituudet[i]);
    free(pituudet[i]); /* Not needed anymore; can release. */
  }
  free(pituudet);
  /* In ascending alphabetical order */
  printf("Aakkosjärjestys:\n");
  for (i = 0; i < lkm; ++i) {
    printf(" %s\n", aakkoset[i]);
    free(aakkoset[i]);
  }
  free(aakkoset);
  return 0;
}
