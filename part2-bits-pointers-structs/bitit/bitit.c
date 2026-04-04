#include "bitit.h"
#include <limits.h>

void scharBitit(signed char x) {
  int num_bits = sizeof(signed char) * CHAR_BIT;
  int count_0 = 0;
  int count_1 = 0;
  int i;

  /* Output the value of x */
  printf("%d\n", x);

  /* Output the bit representation of x and count 0s and 1s */
  for (i = num_bits - 1; i >= 0; i--) {
    int bit = (x >> i) & 1;
    printf("%d", bit);
    if (bit == 0) {
      count_0++;
    } else {
      count_1++;
    }
  }

  /* Output the number of 0 bits and 1 bits */
  printf("%d\n", count_0);
  /* Output the number of 1 bits */
  printf("%d\n", count_1);
}

void shortBitit(short int x) {
  int num_bits = sizeof(short int) * CHAR_BIT;
  int count_0 = 0;
  int count_1 = 0;
  int i;

  /* Output the value of x */
  printf("%d\n", x);

  /* Output the bit representation of x and count 0s and 1s */
  for (i = num_bits - 1; i >= 0; i--) {
    int bit = (x >> i) & 1;
    printf("%d", bit);
    if (bit == 0) {
      count_0++;
    } else {
      count_1++;
    }
  }

  /* Output the number of 0 bits and 1 bits */
  printf("%d\n", count_0);
  /* Output the number of 1 bits */
  printf("%d\n", count_1);
}

void intBitit(int x) {
  int num_bits = sizeof(int) * CHAR_BIT;
  int count_0 = 0;
  int count_1 = 0;
  int i;

  /* Output the value of x */
  printf("%d\n", x);

  /* Output the bit representation of x and count 0s and 1s */
  for (i = num_bits - 1; i >= 0; i--) {
    int bit = (x >> i) & 1;
    printf("%d", bit);
    if (bit == 0) {
      count_0++;
    } else {
      count_1++;
    }
  }

  /* Output the number of 0 bits and 1 bits */
  printf("%d\n", count_0);
  /* Output the number of 1 bits */
  printf("%d\n", count_1);
}

void longBitit(long int x) {
  int num_bits = sizeof(long int) * CHAR_BIT;
  int count_0 = 0;
  int count_1 = 0;
  int i;

  /* Output the value of x */
  printf("%ld\n", x);

  /* Output the bit representation of x and count 0s and 1s */
  for (i = num_bits - 1; i >= 0; i--) {
    int bit = (x >> i) & 1;
    printf("%d", bit);
    if (bit == 0) {
      count_0++;
    } else {
      count_1++;
    }
  }

  /* Output the number of 0 bits and 1 bits */
  printf("%d\n", count_0);
  /* Output the number of 1 bits */
  printf("%d\n", count_1);
}
