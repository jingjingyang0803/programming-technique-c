#include "bitit.h"
#include <limits.h>

void kaannaScharBitit(signed char *x) {
  int num_bits = sizeof(signed char) * CHAR_BIT;
  int i;
  signed char reversed = 0;

  for (i = 0; i < num_bits; i++) {
    unsigned char bit = (*x >> i) & 1;
    reversed |= (bit << (num_bits - 1 - i));
  }
  *x = reversed;
}

void kaannaShortBitit(short *x) {
  int num_bits = sizeof(short) * CHAR_BIT;
  int i;
  short reversed = 0;

  for (i = 0; i < num_bits; i++) {
    unsigned short bit = (*x >> i) & 1;
    reversed |= (bit << (num_bits - 1 - i));
  }
  *x = reversed;
}

void kaannaIntBitit(int *x) {
  int num_bits = sizeof(int) * CHAR_BIT;
  int i;
  int reversed = 0;

  for (i = 0; i < num_bits; i++) {
    unsigned int bit = (*x >> i) & 1;
    reversed |= (bit << (num_bits - 1 - i));
  }
  *x = reversed;
}

void kaannaLongBitit(long *x) {
  int num_bits = sizeof(long) * CHAR_BIT;
  int i;
  long reversed = 0;

  for (i = 0; i < num_bits; i++) {
    unsigned long bit = (*x >> i) & 1;
    reversed |= (bit << (num_bits - 1 - i));
  }
  *x = reversed;
}
