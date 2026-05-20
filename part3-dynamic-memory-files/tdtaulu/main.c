/*
This program demonstrates the use of a file-based array (TdTaulu) to store and
retrieve elements of any type. The program creates a file-based array, writes
random double values to it, reads the values back, and checks if the read values
match the original values. The program also includes functions to create, open,
close, read from, and write to the file-based array.
*/

#include "tdtaulu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  const char *name = "ote.bin";
  const unsigned int count = 3;
  const unsigned int n = count * 100;
  unsigned int u = 0;
  double *dt = malloc(n * sizeof(double));
  char *dt_bytes = (char *)dt;
  double *dt2 = malloc(n * sizeof(double));
  char *dt2_bytes = (char *)dt2;
  int error = 0;
  TdTaulu *tdt = NULL;
  for (u = 0; u < n; ++u) { /* Fill the array dt with random values. */
    dt[u] = ((double)rand() / RAND_MAX) * rand();
  }
  tdt = luoTdTaulu(n, sizeof(double), name);
  for (u = 0; (u + count <= n) && (tdt != NULL) && (!error);
       u += count) { /* Write the values of dt into a file-based array count
                        elements at a time. */
    error = tdtKirj(tdt, u, count, &dt_bytes[u * sizeof(double)]);
  }
  vapautaTdTaulu(tdt);     /* Close the file-based array. */
  tdt = avaaTdTaulu(name); /* Open an existing file-based array. */
  for (u = 0; (u + count <= n) && (tdt != NULL) && (!error);
       u += count) { /* Read elements of the file-based array count elements at
                        a time into the array dt2. */
    error = tdtLue(tdt, u, count, &dt2_bytes[u * sizeof(double)]);
  }
  if (memcmp(dt, dt2, n * sizeof(double)) ==
      0) /* Is dt2 equal to the original dt. */
  {
    printf("Tiedoston kirjoitus ja luku %d alkiota kerrallaan: ok!\n", count);
  } else {
    printf("Tiedoston kirjoitus ja luku %d alkiota kerrallaan: VIRHE!\n",
           count);
  }
  vapautaTdTaulu(tdt);
  remove(name); /* Removes the file. */
  free(dt);
  free(dt2);
  return 0;
}
