#include "fibonacci.h"
#include <stdlib.h> /* Need the function "malloc" for dynamic memory allocation. */

unsigned int *fib_jono(unsigned int n) {
  unsigned int i;
  unsigned int *fibonacci = NULL;

  if (n == 0) {
    return NULL;
  }

  /* Dynamically allocate an array to hold the Fibonacci numbers. */
  fibonacci = (unsigned int *)malloc(n * sizeof(unsigned int));

  if (fibonacci == NULL) {
    return NULL; /* Memory allocation failed. */
  }

  fibonacci[0] = 0;

  /* Calculate the Fibonacci numbers iteratively. */
  if (n > 1) {
    fibonacci[1] = 1;
    for (i = 2; i < n; ++i) {
      fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
  }

  return fibonacci;
}
