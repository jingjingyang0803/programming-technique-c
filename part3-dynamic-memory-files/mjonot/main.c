#include "mjonot.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,
         char *argv[]) { /* Start from index 1 and use size argc - 1. */
  /* This omits the program execution call name in index 0. */
  char **kopiot =
      kopioi_mjt(&argv[1], argc - 1); /* kopiot = Finnish for copies. */
  int i = 0;
  for (i = 0; i < (argc - 1); ++i) {
    printf("argv[%d]: %s, kopiot[%d]: %s\n", i + 1, argv[i + 1], i, kopiot[i]);
    free(kopiot[i]); /* Release the memory of each copied string. */
  }
  free(kopiot); /* Release the memory of the string copy array. */
  return 0;
}
