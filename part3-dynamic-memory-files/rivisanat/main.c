/*
This program reads lines from a file and tokenizes them into words. The function
returns a structure that contains the tokenized lines and the number of lines
and words in each line. The main function demonstrates how to use the
lueRiviSanat function to read from a specified input file and print the
tokenized lines and their word counts.
*/

#include "rivisanat.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *is;
  RiviSanat *rs;
  size_t i, j;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
    return 1;
  }
  is = fopen(argv[1], "r"); /* argv[1] specifies an input file. */
  rs = lueRiviSanat(is);
  i = 0;
  for (i = 0; i < rs->riviLkm; ++i) {
    j = 0;
    printf("Rivi %lu (%lu sanaa):", (unsigned long)i,
           (unsigned long)rs->riviKoot[i]);
    for (j = 0; j < rs->riviKoot[i]; ++j) {
      printf(" %s", rs->rivit[i][j]);
    }
    printf("\n");
  }
  tuhoaRiviSanat(rs);
  return 0;
}
