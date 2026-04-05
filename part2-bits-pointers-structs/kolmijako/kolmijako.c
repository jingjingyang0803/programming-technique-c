#include "kolmijako.h"
#include <stdio.h>

IntPari kolmijako(unsigned int n, int t[], int pivot1, int pivot2, int *p1,
                  int *p2) {
  int p1_val, p2_val; /* Values at the pivot indices. */
  int low, high;      /* Indices for the three-way partitioning. */
  int current;        /* Current index for iterating through the array. */
  IntPari result;

  /* Swap pivots if necessary to ensure value at pivot1 <= value at pivot2 */
  if (t[pivot1] > t[pivot2]) {
    int temp = pivot1;
    pivot1 = pivot2;
    pivot2 = temp;
  }

  p1_val = t[pivot1]; /* Value at pivot1. */
  p2_val = t[pivot2]; /* Value at pivot2. */

  low = 0;           /* Initial index for the first part as first element */
  high = (int)n - 1; /* Initial index for the last part as last element */

  /* Iterate through the array and partition it into three parts */
  current = 0;
  while (current <= high) {
    if (t[current] < p1_val) {
      /* Current element belongs to the first part.
       * Swap it with the element at index low.
       * Both low and current can be advanced,
       * because the element moved to current has already been processed. */
      int temp = t[low];
      t[low] = t[current];
      t[current] = temp;
      low++;
      current++;
    } else if (t[current] >= p2_val) {
      /* Current element belongs to the last part.
       * Swap it with the element at index high.
       * Only decrease high, do NOT advance current,
       * because the element swapped into current has not been processed yet. */
      int temp = t[current];
      t[current] = t[high];
      t[high] = temp;
      high--;
    } else {
      /* Current element belongs to the middle part.
       * It is already in the correct region, so just move forward. */
      current++;
    }
  }

  /* After partitioning:
   * - Elements at indices [0, low) are less than p1_val.
   * - Elements at indices [low, high] are between p1_val and p2_val.
   * - Elements at indices (high, n-1] are greater than or equal to p2_val.
   * Therefore:
   * - The first element in the middle part is at index low.
   * - The first element in the last part is at index high + 1. */
  result.x = low;
  result.y = high + 1;

  /* Update the values pointed to by p1 and p2 if they are not null pointers. */
  if (p1 != 0) {
    *p1 = result.x;
  }
  if (p2 != 0) {
    *p2 = result.y;
  }

  return result;
}
