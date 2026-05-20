/*
EXERCISE: Tokenizing a string
Write a function that reads lines from a file and tokenizes them into words. The
function should return a structure that contains the tokenized lines and the
number of lines and words in each line.
*/

#ifndef RIVISANAT_H
#define RIVISANAT_H

#include <stddef.h>
#include <stdio.h>

typedef struct RiviSanat {
  char ***rivit;
  size_t riviLkm;
  size_t *riviKoot;
} RiviSanat;

RiviSanat *lueRiviSanat(FILE *is);
void tuhoaRiviSanat(RiviSanat *rs);

#endif
