/*
EXERCISE: File-based array

write a module that implements a file-based array. The module should provide
functions to create a new file-based array, open an existing file-based array,
close a file-based array, read elements from a file-based array, and write
elements to a file-based array. The file-based array should be able to store
elements of any type, and the functions should take the size of the elements as
a parameter. The file-based array should also store the number of elements in
the array and the name of the file where the array is stored. The functions
should return appropriate error codes if any operation fails.
*/

#ifndef TDTAULU_H
#define TDTAULU_H

#include <stdio.h>

typedef struct TdTaulu {
  unsigned int n;
  unsigned int alkioKoko;
  const char *tdNimi;
  FILE *td;
} TdTaulu;

TdTaulu *luoTdTaulu(unsigned int n, unsigned int alkioKoko, const char *tdNimi);

TdTaulu *avaaTdTaulu(const char *tdNimi);

void vapautaTdTaulu(TdTaulu *tdt);

int tdtLue(TdTaulu *tdt, unsigned int i, unsigned int count, void *mem);

int tdtKirj(TdTaulu *tdt, unsigned int i, unsigned int count, const void *mem);

#endif
