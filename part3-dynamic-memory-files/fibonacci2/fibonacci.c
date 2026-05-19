/*
 * Fibonacci sequence generator that returns a string of the first n Fibonacci
 * numbers. The string is dynamically allocated and should be freed by the
 * caller.
 */

#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fib_jono_mj(unsigned int n) {
  unsigned int a;
  unsigned int b;
  unsigned int fib;
  unsigned int cap;
  unsigned int used;

  /* Loop variables and temporary storage. */
  unsigned int i;
  unsigned int old_cap;
  int m;
  char buf[32];
  char *str;
  char *tmp;

  /* Initialize the first two Fibonacci numbers and the string buffer. */
  a = 0;
  b = 1;
  cap = 1;  /* Start with a small buffer and grow it as needed. */
  used = 1; /* Start with 1 to account for the null terminator. */

  str = malloc(cap);
  if (str == NULL) {
    return NULL;
  }

  str[0] = '\0';

  for (i = 0; i < n; i++) {
    if (i == 0) {
      fib = 0;
    } else if (i == 1) {
      fib = 1;
    } else {
      fib = a + b;
      a = b;
      b = fib;
    }

    /* Convert the Fibonacci number to a string and calculate the required
     * space. */
    sprintf(buf, "%u", fib);

    if (i == 0) {
      m = strlen(buf);
    } else {
      m = strlen(buf) + 2;
    }

    old_cap = cap;

    while (used + m > cap) {
      cap = cap * 2;
    }

    if (cap != old_cap) {
      tmp = realloc(str, cap);
      if (tmp == NULL) {
        free(str);
        return NULL;
      }
      str = tmp;
    }

    if (i == 0) {
      sprintf(&str[used - 1], "%u", fib);
    } else {
      sprintf(&str[used - 1], ", %u", fib);
    }

    used = used + m;
  }

  if (cap > used) {
    tmp = realloc(str, used);
    if (tmp == NULL) {
      free(str);
      return NULL;
    }
    str = tmp;
  }

  return str;
}
