#include "pikalaj.h"
#include "kolmijako.h"

/* Include standard I/O library if needed */
#if defined(KOLMIJAON_RAJAT) || defined(KOLMIJAON_TYO)
#include <stdio.h>
#endif

/* If KOLMIJAON_TYO is defined, kolmijaonTyo keeps track of the total length of
   all subintervals processed by kolmijako. */
#ifdef KOLMIJAON_TYO
static unsigned int kolmijaonTyo = 0;
#endif

/* Recursive helper function for quicksort. */
static void pikalajitteleRec(int start, int end, int t[]) {
  unsigned int n;
  int p1;
  int p2;

  if (start >= end) {
    return;
  }

  n = (unsigned int)(end - start + 1);

#ifdef KOLMIJAON_RAJAT
  printf("Kolmijako %d %d\n", start, end);
#endif

#ifdef KOLMIJAON_TYO
  kolmijaonTyo += n;
#endif

  p1 = 0;
  p2 = (int)n - 1;

  kolmijako(n, t + start, p1, p2, &p1, &p2);

  pikalajitteleRec(start, start + p1 - 1, t);
  pikalajitteleRec(start + p1 + 1, start + p2 - 1, t);
  pikalajitteleRec(start + p2 + 1, end, t);
}

/* Public function to sort the array t from index start to index end. */
void pikalajittele(int start, int end, int t[]) {
#ifdef KOLMIJAON_TYO
  kolmijaonTyo = 0;
#endif

  pikalajitteleRec(start, end, t);

#ifdef KOLMIJAON_TYO
  printf("Kolmijaon kokonaistyö: %u\n", kolmijaonTyo);
#endif
}
