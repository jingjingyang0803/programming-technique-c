/*
The main function in this file tests the max2D function defined in gotokoe.h.
It creates a 2D array of random integers, finds the maximum value using both a
manual method and the max2D function, and compares the results to ensure they
match. Finally, it frees the allocated memory before exiting.
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gotokoe.h"

int main(int argc, char *argv[]) {
  int kork, lev;
  int **t2d;
  int i, j;
  int max1, max2;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <kork> <lev>\n", argv[0]);
    return 1;
  }
  kork = atoi(argv[1]);
  lev = atoi(argv[2]);
  t2d = malloc(kork * sizeof(int *));
  i = 0, j = 0;
  max1 = INT_MIN, max2 = INT_MIN;
  srand(time(NULL));
  for (i = 0; i < kork; ++i) {
    t2d[i] = malloc(lev * sizeof(int));
    for (j = 0; j < lev; ++j) {
      t2d[i][j] = rand();
      max1 = (max1 < t2d[i][j]) ? t2d[i][j] : max1;
    }
  }
  max2 = max2D(t2d, kork, lev);
  if (max1 == max2) {
    printf("Maksimi ok, %d\n", max1);
  } else {
    printf("Virhe, maksimi on %d eikä %d\n", max1, max2);
  }
  for (i = 0; i < kork; ++i) {
    free(t2d[i]);
  }
  free(t2d);
  return 0;
}
