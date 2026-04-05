#include "vaihto.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x, y, z;
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <num1> <num2> <num3>\n", argv[0]);
    return 1;
  }

  x = atoi(argv[1]);
  y = atoi(argv[2]);
  z = atoi(argv[3]);
  printf("%d %d %d\n", x, y, z);
  vaihda(&x, &y);
  printf("%d %d %d\n", x, y, z);
  jarjesta(&x, &y, &z);
  printf("%d %d %d\n", x, y, z);
  return 0;
}
