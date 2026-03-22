/*
EXERCISE: Unsigned Intervals
*/
#include "unsigned.h"
#include <stdio.h>

int main(void) {
  unsigned char r1 = 40, s1 = 75;
  unsigned short r2 = 65535, s2 = 65535;
  unsigned int r3 = 400000, s3 = 750000;
  unsigned long r4 = 400000000, s4 = 1500000000;

  ucharIntervalli(r1, s1);
  ushortIntervalli(r2, s2);
  uintIntervalli(r3, s3);
  ulongIntervalli(r4, s4);

  return 0;
}
