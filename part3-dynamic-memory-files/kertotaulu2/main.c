#include "kertotaulu.h"
#include <stdio.h>
#include <stdlib.h>

#define uint unsigned int

int main(int argc, char *argv[]) {
  uint a, b, c, d;
  char **kertotaulu;
  uint i;

  if (argc < 5) {
    fprintf(stderr, "Usage: %s a b c d\n", argv[0]);
    return 1;
  }
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);
  d = atoi(argv[4]);

  kertotaulu = luo_kertotaulu_mjt(a, b, c, d);

  /* Print the multiplication table and free the allocated memory. */
  i = 0;
  for (i = 0; i <= (d - c + 1); ++i) {
    printf("%s\n", kertotaulu[i]);
    free(kertotaulu[i]);
  }
  free(kertotaulu);
  return 0;
}
