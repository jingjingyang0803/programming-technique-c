#include "kolmijako.h"

IntPari kolmijako(unsigned int n, int t[], int pivot1, int pivot2, int *p1,
                  int *p2) {
  IntPari result;
  unsigned int less1,
      less2; /* Indices for the first and second pivots after partitioning. */
  int i;
  int temp;

  /* Swap pivots if necessary to ensure value at pivot1 <= value at pivot2 */
  if (t[pivot1] > t[pivot2]) {
    temp = pivot1;
    pivot1 = pivot2;
    pivot2 = temp;
  }

  /* First pass: Move elements less than the first pivot to the front. */
  less1 = 0;
  for (i = 0; i < n; ++i) {
    if (t[i] < t[pivot1]) { /* Current element belongs to the first part. */
      /* Swap the current element with the element at index less1. */
      temp = t[i];
      t[i] = t[less1];
      t[less1] = temp;

      /* Update pivot indices if they were swapped. */
      if (pivot1 == less1) {
        pivot1 = i;
      } else if (pivot2 == less1) {
        pivot2 = i;
      }

      /* Move the boundary of the first part forward. */
      less1++;
    }
  }

  /* Move the first pivot to its final position. */
  temp = t[less1];
  t[less1] = t[pivot1];
  t[pivot1] = temp;

  /* Update pivot2 if it was swapped with the first pivot. */
  if (pivot2 == less1) {
    pivot2 = pivot1;
  }

  /* Second pass: Move elements less than the second pivot (but greater than or
   * equal to the first pivot) to the middle. */
  less2 = less1 + 1; /* Start of the middle part. */
  for (i = less2; i < (int)n; ++i) {
    if (t[i] < t[pivot2]) { /* Current element belongs to the middle part. */
      /* Swap the current element with the element at index less2. */
      temp = t[i];
      t[i] = t[less2];
      t[less2] = temp;

      if (pivot2 == less2) {
        pivot2 = i;
      }

      less2++;
    }
  }

  /* Move the second pivot to its final position. */
  temp = t[less2];
  t[less2] = t[pivot2];
  t[pivot2] = temp;

  /* Set the return values. */
  result.x = less1;
  result.y = less2;

  /* Update the values pointed to by p1 and p2 if they are not null pointers. */
  if (p1 != 0) {
    *p1 = less1;
  }
  if (p2 != 0) {
    *p2 = less2;
  }

  return result;
}
