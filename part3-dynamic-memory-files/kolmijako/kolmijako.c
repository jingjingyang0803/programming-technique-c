#include "kolmijako.h"

#include <stdlib.h>
#include <string.h>

/* Returns a pointer to the i-th element in the array */
static char *alkio(char *t, size_t size, size_t i) { return t + i * size; }

/* Swaps the i-th and j-th elements in the array */
static void vaihda(char *t, size_t size, size_t i, size_t j) {
  size_t k;
  char tmp;

  if (i == j) {
    return;
  }

  for (k = 0; k < size; k++) {
    tmp = t[i * size + k];
    t[i * size + k] = t[j * size + k];
    t[j * size + k] = tmp;
  }
}

/* The main function that performs 3-way partitioning */
void kolmijako_gen(void *t, size_t n, size_t size, size_t pivot1, size_t pivot2,
                   int (*cmp)(const void *, const void *), size_t *p1,
                   size_t *p2) {
  char *a;
  char *low;
  char *high;
  size_t vasen;
  size_t oikea;
  size_t i;

  a = (char *)t;

  if (n == 0) {
    if (p1 != 0) {
      *p1 = 0;
    }
    if (p2 != 0) {
      *p2 = 0;
    }
    return;
  }

  if (n == 1) {
    if (p1 != 0) {
      *p1 = 0;
    }
    if (p2 != 0) {
      *p2 = 0;
    }
    return;
  }

  if (cmp(alkio(a, size, pivot2), alkio(a, size, pivot1))) {
    vaihda(a, size, pivot1, pivot2);
  }

  vaihda(a, size, 0, pivot1);

  if (pivot2 == 0) {
    pivot2 = pivot1;
  }

  vaihda(a, size, n - 1, pivot2);

  low = malloc(size);
  high = malloc(size);

  if (low == 0 || high == 0) {
    free(low);
    free(high);
    return;
  }

  memcpy(low, alkio(a, size, 0), size);
  memcpy(high, alkio(a, size, n - 1), size);

  vasen = 1;
  oikea = n - 2;
  i = 1;

  while (i <= oikea) {
    if (cmp(alkio(a, size, i), low)) {
      vaihda(a, size, i, vasen);
      vasen++;
      i++;
    } else if (!cmp(alkio(a, size, i), high)) {
      while (i < oikea && !cmp(alkio(a, size, oikea), high)) {
        oikea--;
      }

      vaihda(a, size, i, oikea);
      oikea--;

      if (cmp(alkio(a, size, i), low)) {
        vaihda(a, size, i, vasen);
        vasen++;
      }

      i++;
    } else {
      i++;
    }
  }

  vasen--;
  oikea++;

  vaihda(a, size, 0, vasen);
  vaihda(a, size, n - 1, oikea);

  if (p1 != 0) {
    *p1 = vasen;
  }

  if (p2 != 0) {
    *p2 = oikea;
  }

  free(low);
  free(high);
}
