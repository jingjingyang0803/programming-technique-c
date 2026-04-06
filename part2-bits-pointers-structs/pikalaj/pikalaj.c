#include "pikalaj.h"
#include "kolmijako.h"

void Pikalajittele(int start, int end, int t[]) {
  int less1, less2;
  int x, y;
  int n;

  /* Base case: If the segment is empty or has one element, it's already sorted.
   */
  if (start >= end) {
    return;
  }

  /* Partition the segment of the array into three parts using kolmijako. */
  n = end - start + 1;
  kolmijako(n, t + start, 0, n - 1, &less1, &less2);

  /* Calculate the actual indices of the pivots in the original array. */
  x = start + less1;
  y = start + less2;

  /* Recursively sort the three parts. */
  Pikalajittele(start, x - 1, t); /* Sort the first part. */
  Pikalajittele(x, y - 1, t);     /* Sort the middle part. */
  Pikalajittele(y, end, t);       /* Sort the last part. */
}
