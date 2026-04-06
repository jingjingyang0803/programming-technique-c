#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h> /* Need the function "free" for releasing memory. */

int main(void) {
  unsigned int *fibonacci = fib_jono(15); /* The 15 first Fibonacci numbers. */
  int i = 0;
  for (i = 0; i < 15; ++i) {
    printf(" %u", fibonacci[i]);
  }
  printf("\n");
  free(fibonacci); /* Release the dynamically allocated memory. */
  return 0;
}
