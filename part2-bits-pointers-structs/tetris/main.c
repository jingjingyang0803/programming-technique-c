#include <stdio.h>
/* Remember to declare the paivita function in the header tetris.h */
#include "tetris.h"

/* A static two-dimensional char array of size 20x10 is defined below. Each
   filled square is marked with the character 'x'. Each subarray of size 10
   is initialized with a string literal (whose end character is truncated).  */
char grid[20][10] = {"          ", /* Row 0: top row.                   */
                     "  x   x   ", /* Row 1: second row.                */
                     " xx   xxx ", /* ...and so on...                   */
                     "xxx xxxxxx", "xxxxxxxxxx", /* Row 4: full. */
                     "xxxxxxxxxx", /* Row 5: full.                      */
                     "xxxxxx xxx", "xxxxxxx xx", "x xxxxxxxx", "xxx xxx xx",
                     "xxxxxx xxx", "x xx xxx x", "xxxxxxxxx ", "xxx xxx xx",
                     "xxxxx xx x", " xxxxxxxxx", "xxx xxx xx", "x xxxx xxx",
                     "xxxxx xxxx",  /* Row 18: second-last row.          */
                     "xxxxxxxx x"}; /* Row 19: bottom row.               */

int main(void) {
  int i = 0;
  paivita(grid);           /* Remove empty rows.  */
  for (i = 0; i < 20; ++i) /* Output the grid.    */
  {
    printf("%.10s\n", grid[i]); /* Each round prints one 10-character row.   */
  }
  return 0;
}
