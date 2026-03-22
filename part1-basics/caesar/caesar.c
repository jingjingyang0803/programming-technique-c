#include "caesar.h"
#include <string.h>

void caesarKoodaa(char mj[], char orig[], char perm[]) {
  int i, j;

  for (i = 0; i < strlen(mj); i++) {
    for (j = 0; j < strlen(orig); j++) {
      /* Check if the current character in mj matches the original alphabet */
      if (mj[i] == orig[j]) {
        /* If it matches, replace it with the corresponding character in the
         * permuted alphabet */
        mj[i] = perm[j];
        /* Break the inner loop since we found a match and replaced the
         * character */
        break;
      }
    }
  }
}