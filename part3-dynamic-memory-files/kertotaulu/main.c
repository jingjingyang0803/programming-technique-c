#include "kertotaulu.h"
#include <stdio.h>
#include <stdlib.h>

void tulostaKertotaulu(const Kertotaulu *kt);

int main(int argc, char *argv[]) { /* argv[1]...argv[4] are assumed to give the
                                      parameters a, b, c ja d. */
  Kertotaulu *kt; /* Declare a pointer to a Kertotaulu structure to hold the
                     multiplication table. */

  if (argc != 5) {
    fprintf(stderr, "Usage: %s a b c d\n", argv[0]);
    return 1;
  }

  kt =
      luoKertotaulu(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

  if (kt == NULL) {
    fprintf(stderr, "Error creating multiplication table.\n");
    return 1;
  }

  tulostaKertotaulu(kt);
  tuhoaKertotaulu(kt);
  return 0;
}

void tulostaKertotaulu(const Kertotaulu *kt) {
  uint max, width;
  uint i, j; /* Loop variables. */

  /* Calculate the maximum value in the multiplication table to determine the
     width needed for printing. */
  max = (kt->b) * (kt->d);
  width = 1;
  while (max >= 10) {
    max /= 10;
    width++;
  }
  width += 1; /* Add one extra space for separation. */

  for (i = 0; i <= (kt->d - kt->c + 1); ++i) /* Rows. */
  {
    for (j = 0; j <= (kt->b - kt->a + 1); ++j) /* Columns. */
    {
      if ((i > 0) || (j > 0)) /* Check that we are not at [0][0]. */
      {
        printf("%*u", width,
               kt->kertotaulu[i][j]); /* Print using calculated width. */
      } else {
        printf("%*s", width,
               ""); /* The empty top left index [0][0] gets width spaces. */
      }
    }
    printf("\n");
  }
}
