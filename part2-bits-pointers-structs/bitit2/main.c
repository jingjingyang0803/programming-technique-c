#include "bitit.h"
#include <limits.h>
#include <stdio.h>

#define NUMBER 2015L

void printScharBits(signed char x);
void printShortBits(short int x);
void printIntBits(int x);
void printLongBits(long int x);

int main(void) {
  long int lx = NUMBER;
  signed char cx = (signed char)lx;
  short int sx = (short int)lx;
  int ix = (int)lx;

  printScharBits(cx);
  kaannaScharBitit(&cx);
  printScharBits(cx);
  printf("\n");

  printShortBits(sx);
  kaannaShortBitit(&sx);
  printShortBits(sx);
  printf("\n");

  printIntBits(ix);
  kaannaIntBitit(&ix);
  printIntBits(ix);
  printf("\n");

  printLongBits(lx);
  kaannaLongBitit(&lx);
  printLongBits(lx);

  return 0;
}

void printScharBits(signed char x) {
  int num_bits = sizeof(signed char) * CHAR_BIT;
  int i;
  unsigned char ux = (unsigned char)x;

  /* Print value */
  printf("%d\n", x);

  /* Print bits */
  for (i = num_bits - 1; i >= 0; i--) {
    int bit = (ux >> i) & 1;
    printf("%d", bit);
  }
  printf("\n");
}

void printShortBits(short int x) {
  int num_bits = sizeof(short int) * CHAR_BIT;
  int i;
  unsigned short ux = (unsigned short)x;

  /* Print value */
  printf("%d\n", x);

  /* Print bits */
  for (i = num_bits - 1; i >= 0; i--) {
    int bit = (ux >> i) & 1;
    printf("%d", bit);
  }
  printf("\n");
}

void printIntBits(int x) {
  int num_bits = sizeof(int) * CHAR_BIT;
  int i;
  unsigned int ux = (unsigned int)x;

  /* Print value */
  printf("%d\n", x);

  /* Print bits */
  for (i = num_bits - 1; i >= 0; i--) {
    int bit = (ux >> i) & 1;
    printf("%d", bit);
  }
  printf("\n");
}

void printLongBits(long int x) {
  int num_bits = sizeof(long int) * CHAR_BIT;
  int i;
  unsigned long ux = (unsigned long)x;

  /* Print value */
  printf("%ld\n", x);

  /* Print bits */
  for (i = num_bits - 1; i >= 0; i--) {
    int bit = (ux >> i) & 1;
    printf("%d", bit);
  }
  printf("\n");
}
