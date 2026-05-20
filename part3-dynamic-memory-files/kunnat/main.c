/*
This program reads municipality data from a specified input file, creates Kunta
objects for each municipality, and stores them in an array. The program then
sorts the municipalities in descending order by their areas and prints the
sorted list. The program also includes functions to create a new Kunta object,
read municipalities from a file, and free the memory used by a Kunta object.

The input file should have the following format: <name> <population> <area>,
with each municipality on a separate line.
The program handles memory allocation and deallocation appropriately, and it
returns error codes if any operation fails.
*/

#include "kunnat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Compares two Kunta objects primarily based on their areas
   and seconcarily based on their names. */
static int pintaalaVrt(const void *a, const void *b) {
  const Kunta *const *x = a;
  const Kunta *const *y = b;
  float paA = (*x)->pintaala;
  float paB = (*y)->pintaala;
  return (paA > paB) ? -1 : ((paA < paB) ? 1 : strcmp((*x)->nimi, (*y)->nimi));
}

int main(int argc, char *argv[]) {
  FILE *syote;
  size_t kuntaLkm = 0;
  size_t i = 0;
  Kunta **kunnat;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
    return 1;
  }
  syote = fopen(argv[1], "r"); /* argv[1] specifies the input file. */
  if (syote == NULL) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return 1;
  }
  kunnat = lueKunnat(syote, &kuntaLkm);
  fclose(syote); /* The data was read so the file can now be closed. */
  /* Sort the municipalities into descending order by their areas. */
  qsort(kunnat, kuntaLkm, sizeof(Kunta *), pintaalaVrt);
  for (i = 0; i < kuntaLkm; ++i) { /* "asukasta" is Finnish for "residents". */
    printf("%25s: %6.1f km^2 ja %6u asukasta\n", kunnat[i]->nimi,
           kunnat[i]->pintaala, kunnat[i]->vakiluku);
    tuhoaKunta(kunnat[i]);
  }
  free(kunnat);
  return 0;
}
