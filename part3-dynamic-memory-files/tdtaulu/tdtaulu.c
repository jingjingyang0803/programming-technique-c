#include "tdtaulu.h"

#include <stdlib.h>
#include <string.h>

/* Helper function to copy a string. */
static char *kopioi_nimi(const char *nimi) {
  char *uusi;
  size_t pituus;

  if (nimi == NULL) {
    return NULL;
  }

  pituus = strlen(nimi);

  uusi = malloc((pituus + 1) * sizeof(char));
  if (uusi == NULL) {
    return NULL;
  }

  strcpy(uusi, nimi);
  return uusi;
}

/* Helper function to calculate the offset of the first element in the
 * file-based array. */
static long alku_offset(void) { return (long)(2 * sizeof(unsigned int)); }

/* Function to create a new file-based array. */
TdTaulu *luoTdTaulu(unsigned int n, unsigned int alkioKoko,
                    const char *tdNimi) {
  TdTaulu *tdt;
  unsigned int i;
  unsigned int bytes;
  unsigned char zero;

  tdt = malloc(sizeof(TdTaulu));
  if (tdt == NULL) {
    return NULL;
  }

  tdt->n = n;
  tdt->alkioKoko = alkioKoko;
  tdt->tdNimi = kopioi_nimi(tdNimi);
  tdt->td = NULL;

  if (tdt->tdNimi == NULL) {
    free(tdt);
    return NULL;
  }

  tdt->td = fopen(tdNimi, "wb+");
  if (tdt->td == NULL) {
    free((char *)tdt->tdNimi);
    free(tdt);
    return NULL;
  }

  if (fwrite(&tdt->n, sizeof(unsigned int), 1, tdt->td) != 1) {
    vapautaTdTaulu(tdt);
    return NULL;
  }

  if (fwrite(&tdt->alkioKoko, sizeof(unsigned int), 1, tdt->td) != 1) {
    vapautaTdTaulu(tdt);
    return NULL;
  }

  zero = 0;
  bytes = n * alkioKoko;

  for (i = 0; i < bytes; i++) {
    if (fwrite(&zero, sizeof(unsigned char), 1, tdt->td) != 1) {
      vapautaTdTaulu(tdt);
      return NULL;
    }
  }

  return tdt;
}

/* Function to open an existing file-based array. */
TdTaulu *avaaTdTaulu(const char *tdNimi) {
  TdTaulu *tdt;

  tdt = malloc(sizeof(TdTaulu));
  if (tdt == NULL) {
    return NULL;
  }

  tdt->n = 0;
  tdt->alkioKoko = 0;
  tdt->tdNimi = kopioi_nimi(tdNimi);
  tdt->td = NULL;

  if (tdt->tdNimi == NULL) {
    free(tdt);
    return NULL;
  }

  tdt->td = fopen(tdNimi, "rb+");
  if (tdt->td == NULL) {
    free((char *)tdt->tdNimi);
    free(tdt);
    return NULL;
  }

  if (fread(&tdt->n, sizeof(unsigned int), 1, tdt->td) != 1) {
    vapautaTdTaulu(tdt);
    return NULL;
  }

  if (fread(&tdt->alkioKoko, sizeof(unsigned int), 1, tdt->td) != 1) {
    vapautaTdTaulu(tdt);
    return NULL;
  }

  return tdt;
}

/* Function to close a file-based array and free the associated memory. */
void vapautaTdTaulu(TdTaulu *tdt) {
  if (tdt == NULL) {
    return;
  }

  if (tdt->td != NULL) {
    fclose(tdt->td);
  }

  free((char *)tdt->tdNimi);
  free(tdt);
}

/* Function to read elements from a file-based array. */
int tdtLue(TdTaulu *tdt, unsigned int i, unsigned int count, void *mem) {
  long offset;
  size_t maara;

  if (tdt == NULL || tdt->td == NULL || mem == NULL) {
    return 1;
  }

  if (i > tdt->n || count > tdt->n - i) {
    return 1;
  }

  offset = alku_offset() + (long)(i * tdt->alkioKoko);

  if (fseek(tdt->td, offset, SEEK_SET) != 0) {
    return 1;
  }

  maara = (size_t)count * tdt->alkioKoko;

  if (fread(mem, 1, maara, tdt->td) != maara) {
    return 1;
  }

  return 0;
}

/* Function to write elements to a file-based array. */
int tdtKirj(TdTaulu *tdt, unsigned int i, unsigned int count, const void *mem) {
  long offset;
  size_t maara;

  if (tdt == NULL || tdt->td == NULL || mem == NULL) {
    return 1;
  }

  if (i > tdt->n || count > tdt->n - i) {
    return 1;
  }

  offset = alku_offset() + (long)(i * tdt->alkioKoko);

  if (fseek(tdt->td, offset, SEEK_SET) != 0) {
    return 1;
  }

  maara = (size_t)count * tdt->alkioKoko;

  if (fwrite(mem, 1, maara, tdt->td) != maara) {
    return 1;
  }

  return 0;
}
