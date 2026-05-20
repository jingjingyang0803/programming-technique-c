/*
EXERCISE: Municipality statistics

Write a module that defines a structure for storing information about a
municipality, including its name, population, and area. The module should
provide functions to create a new municipality, read municipalities from a file,
and free the memory used by a municipality. The function to read municipalities
from a file should return an array of pointers to municipalities and the number
of municipalities read. The file format should be as follows: <name>
<population> <area> Each municipality should be stored on a separate line in the
file. The functions should return appropriate error codes if any operation
fails.
*/

#ifndef KUNNAT_H
#define KUNNAT_H

#include <stddef.h>
#include <stdio.h>

typedef struct Kunta {
  const char *nimi;
  unsigned int vakiluku;
  float pintaala;
} Kunta;

Kunta *luoKunta(const char *nimi, unsigned int vakiluku, float pintaala);
Kunta **lueKunnat(FILE *in, size_t *count);
void tuhoaKunta(Kunta *k);

#endif
