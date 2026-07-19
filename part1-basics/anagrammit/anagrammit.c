#include "anagrammit.h"
#include <limits.h>
#include <string.h>

int anagrammeja(char mj1[], char mj2[]) {

  int balance[UCHAR_MAX + 1] = {0}; /* Array to keep track of character counts */
  int i;

  /* Update balance array based on characters in both strings */
  for (i = 0; mj1[i] != '\0'; i++) {
    balance[(unsigned char)mj1[i]]++;
    balance[(unsigned char)mj2[i]]--;
  }

  /* Check if all counts in balance are zero, which indicates that the strings
   are anagrams */
  for (i = 0; i <= UCHAR_MAX; i++) {
    if (balance[i] != 0) {
      return 0;
    }
  }

  return 1;
}
