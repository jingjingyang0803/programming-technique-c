#include "tetris.h"

void paivita(char grid[GRID_HEIGHT][GRID_WIDTH]) {
  int i, j, k;
  /* Check each row from the bottom up. */
  for (i = GRID_HEIGHT - 1; i >= 0; --i) {
    /* Assume the row is full until we find an empty square. */
    int isFull = 1;
    for (j = 0; j < GRID_WIDTH; ++j) {
      if (grid[i][j] != 'x') {
        isFull = 0;
        break; /* No need to check the rest of the row. */
      }
    }
    /* If the row is full */
    if (isFull) {
      /* Move all rows above the full row one step down. */
      for (k = i; k > 0; --k) {
        for (j = 0; j < GRID_WIDTH; ++j) {
          grid[k][j] = grid[k - 1][j];
        }
      }
      /* Fill the topmost row with spaces. */
      for (j = 0; j < GRID_WIDTH; ++j) {
        grid[0][j] = ' ';
      }
      ++i; /* Check the same row again after shifting. */
    }
  }
}
