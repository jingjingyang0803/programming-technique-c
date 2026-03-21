#include "muunto.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void muunna(char mj[]) {
  int i, j;
  char temp;

  /* Change case */
  for (i = 0; mj[i] != '\0'; i++) {
    if (isupper(mj[i])) {
      mj[i] = tolower(mj[i]);
    } else if (islower(mj[i])) {
      mj[i] = toupper(mj[i]);
    }
  }

  /* Reverse the string */
  for (i = 0, j = strlen(mj) - 1; i < j; i++, j--) {
    temp = mj[i];
    mj[i] = mj[j];
    mj[j] = temp;
  }
}