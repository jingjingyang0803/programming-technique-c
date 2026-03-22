#include "unsigned.h"
#include <stdio.h>

void ucharIntervalli(unsigned char r, unsigned char s) {
  unsigned char i, next;

  printf("unsigned char:");

  i = (unsigned char)(-r);

  /* negative side: -r ... -1 */
  while (1) {
    printf(" %u", i);
    next = i + s;
    /* If next < i, then an overflow has occurred and we have wrapped around
       to the non-negative side. */
    if (next < i) {
      i = next;
      break;
    }
    i = next;
  }

  /* non-negative side: 0 ... r */
  while (i <= r) {
    printf(" %u", i);
    next = i + s;
    /* If next < i, then an overflow has occurred and we have wrapped around
       to the negative side. If next > r, then we have exceeded the upper
       bound of the interval. In either case, we should stop. */
    if (next < i || next > r) {
      break;
    }
    i = next;
  }

  printf("\n");
}

void ushortIntervalli(unsigned short r, unsigned short s) {
  unsigned short i, next;

  printf("unsigned short:");

  i = (unsigned short)(-r);

  while (1) {
    printf(" %u", i);
    next = i + s;
    if (next < i) {
      i = next;
      break;
    }
    i = next;
  }

  while (i <= r) {
    printf(" %u", i);
    next = i + s;
    if (next < i || next > r) {
      break;
    }
    i = next;
  }

  printf("\n");
}

void uintIntervalli(unsigned int r, unsigned int s) {
  unsigned int i, next;

  printf("unsigned int:");

  i = (unsigned int)(-r);

  while (1) {
    printf(" %u", i);
    next = i + s;
    if (next < i) {
      i = next;
      break;
    }
    i = next;
  }

  while (i <= r) {
    printf(" %u", i);
    next = i + s;
    if (next < i || next > r) {
      break;
    }
    i = next;
  }

  printf("\n");
}

void ulongIntervalli(unsigned long r, unsigned long s) {
  unsigned long i, next;

  printf("unsigned long:");

  i = (unsigned long)(-r);

  while (1) {
    printf(" %lu", i);
    next = i + s;
    if (next < i) {
      i = next;
      break;
    }
    i = next;
  }

  while (i <= r) {
    printf(" %lu", i);
    next = i + s;
    if (next < i || next > r) {
      break;
    }
    i = next;
  }

  printf("\n");
}