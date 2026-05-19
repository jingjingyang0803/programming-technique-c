#include "genhaku.h"
#include <stddef.h>

size_t etsi(void *arr, size_t n, void *key, size_t m, size_t sz) {
  char *a;
  char *b;
  size_t i;
  size_t j;
  size_t k;
  int match;

  a = arr;
  b = key;

  if (m == 0) {
    return 0;
  }

  if (m > n) {
    return n;
  }

  for (i = 0; i <= n - m; i++) {
    match = 1;

    for (j = 0; j < m && match; j++) {
      for (k = 0; k < sz; k++) {
        if (a[(i + j) * sz + k] != b[j * sz + k]) {
          match = 0;
          break;
        }
      }
    }

    if (match) {
      return i;
    }
  }

  return n;
}
