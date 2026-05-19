#include "gotokoe.h"

/*
The max2D function takes a 2D array of integers (t2d) and its dimensions (h for
height and w for width) as input and returns the maximum value found in the
array. The function uses goto statements to control the flow of the logic,
iterating through each element of the array and updating the maximum value when
a larger value is found.
*/
int max2D(int **t2d, int h, int w) {
  int i = 0;
  int j = 0;
  int max = t2d[0][0];

  goto CHECK_I;

CHECK_I:
  if (i >= h)
    goto DONE;

  j = 0;
  goto CHECK_J;

CHECK_J:
  if (j >= w)
    goto NEXT_I;

  if (t2d[i][j] > max)
    goto SET_MAX;

  goto NEXT_J;

SET_MAX:
  max = t2d[i][j];
  goto NEXT_J;

NEXT_J:
  j++;
  goto CHECK_J;

NEXT_I:
  i++;
  goto CHECK_I;

DONE:
  return max;
}
