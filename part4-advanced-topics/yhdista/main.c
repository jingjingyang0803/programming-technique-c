/*
This program demonstrates how to concatenate command line parameters using a
function that takes a variable number of string arguments. The program starts
with an empty string and concatenates the command line parameters in groups of
three until there are no more parameters left. If there are one or two
parameters left after processing groups of three, it concatenates those as well.
Finally, it prints the concatenated result and its length.
*/

#include "yhdista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int i = 0;
  char *mj = malloc(1);
  mj[0] = '\0'; /* Start with an empty string. */
  for (i = 1; (i + 3) <= argc;
       i += 3) { /* Keep adding 3 more command line parameters to the end of mj
                    as long as possible. */
    char *tmp = mj;
    mj = yhdista(tmp, argv[i], argv[i + 1], argv[i + 2], NULL);
    free(tmp); /* Release the old mj. */
  }
  if ((i + 2) == argc) /* Are there still 2 command line parameters left? */
  {
    char *tmp = mj;
    mj = yhdista(mj, argv[i], argv[i + 1], NULL);
    free(tmp);
  } else if ((i + 1) == argc) /* Is here still 1 command line parameter left? */
  {
    char *tmp = mj;
    mj = yhdista(mj, argv[i], NULL);
    free(tmp);
  }
  printf("Parametrien liitos: %s (pituus: %lu)\n", mj,
         (unsigned long)strlen(mj));
  free(mj);
  return 0;
}
