#include "mjonot.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char **kopioi_mjt(char **merkkijonot, int koko) {
  int i, j;
  char **kopiot; /* Declare a pointer to an array of strings (array of char
                    pointers). */
  size_t len;

  kopiot = malloc(koko * sizeof(char *)); /* Allocate memory for the array
                             of string pointers. */
  if (kopiot == NULL) {
    return NULL; /* Return NULL if memory allocation fails. */
  }

  for (i = 0; i < koko; ++i) {
    len = strlen(merkkijonot[i]) + 1; /* Calculate the length of the string,
                              including space for the null terminator. */
    kopiot[i] = malloc(len * sizeof(char)); /* Allocate memory for each copied
                          string, including space for the null terminator. */
    if (kopiot[i] == NULL) {
      /* If memory allocation fails, free previously allocated memory and return
       * NULL. */
      for (j = 0; j < i; ++j) {
        free(kopiot[j]); /* Free previously allocated strings. */
      }
      free(kopiot); /* Free the array of string pointers. */
      return NULL;  /* Return NULL to indicate failure. */
    }
    strcpy(kopiot[i], merkkijonot[i]); /* Copy the string from the input array
                                          to the newly allocated memory. */
  }

  return kopiot; /* Return the array of copied strings. */
}
