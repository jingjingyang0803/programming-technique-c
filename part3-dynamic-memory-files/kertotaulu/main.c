#include "kertotaulu.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { /* argv[1]...argv[4] are assumed to give the
                                      parameters a, b, c ja d. */
  Kertotaulu *kt;
  uint i = 0;
  uint j = 0;
  uint width;
  uint max;

  if (argc != 5) {
    fprintf(stderr, "Usage: %s a b c d\n", argv[0]);
    return 1;
  }
  kt =
      luoKertotaulu(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

  /* Calculate the width needed for printing the column headers and values. */
  width = 1;
  max = kt->b * kt->d; /* The largest value in the multiplication table is
                          kt->b * kt->d. */
  while (max >= 10) {  /* The largest value in the multiplication table
                         is kt->b * kt->d. */
    width++;
    max /= 10; /* Reduce max to calculate the number of digits in the
                 largest value. */
  }
  width += 1; /* Add 1 for spacing between columns. */
  printf("Width for printing: %u\n", width); /* Print the calculated width. */

  /* Print the column headers. */
  printf("%*s", width, " "); /* Print the top-left corner cell. */
  for (j = kt->a; j <= kt->b; ++j) {
    printf("%*u", width, j);
  }
  printf("\n");

  /* Print the multiplication table. */
  for (i = kt->c; i <= kt->d; ++i) { /* Loop through each row. */
    printf("%4u", i);                /* Print the row header. */
    for (j = kt->a; j <= kt->b; ++j) {
      printf("%*u", width, kt->kertotaulu[i - kt->c][j - kt->a]);
    }
    printf("\n");
  }
  tuhoaKertotaulu(kt);
  return 0;
}
