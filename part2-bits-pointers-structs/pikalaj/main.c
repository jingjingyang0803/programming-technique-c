/* Test my quicksort solution with some fairly large random arrays*/
#include "pikalaj.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int t[1000];
  int i;

  /* Fill the array with random integers. */
  for (i = 0; i < 1000; ++i) {
    t[i] = rand() % 10000; /* Random integers between 0 and 9999. */
  }
  printf("\n");

  /* Sort the array using our quicksort implementation. */
  Pikalajittele(0, 999, t);

  for (i = 0; i < 1000; ++i) {
    printf("%d ", t[i]);
  }
  printf("\n");

  return 0;
}
