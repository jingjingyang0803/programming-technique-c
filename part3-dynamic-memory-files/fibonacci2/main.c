#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *fibonacci;

  if (argc < 2) {
    return 1;
  }

  fibonacci = fib_jono_mj(atoi(argv[1]));

  printf("%s\n", fibonacci);

  free(fibonacci);

  return 0;
}
