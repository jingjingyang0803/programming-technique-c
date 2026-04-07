#include "kertotaulu.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { /* argv[1]...argv[4] are assumed to give the
                                      parameters a, b, c ja d. */
  Kertotaulu *kt;
  uint i = 0;
  uint j = 0;
  if (argc != 5) {
    fprintf(stderr, "Usage: %s a b c d\n", argv[0]);
    return 1;
  }
  kt =
      luoKertotaulu(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

  /* Print the column headers. */
  printf("    ");
  for (j = kt->a; j <= kt->b; ++j) {
    printf("%4u", j);
  }
  printf("\n");

  /* Print the multiplication table. */
  for (i = kt->c; i <= kt->d; ++i) { /* Loop through each row. */
    printf("%4u", i);                /* Print the row header. */
    for (j = kt->a; j <= kt->b; ++j) {
      printf("%4u", kt->kertotaulu[i - kt->c][j - kt->a]);
    }
    printf("\n");
  }
  tuhoaKertotaulu(kt);
  return 0;
}
