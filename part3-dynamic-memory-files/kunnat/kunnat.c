#include "kunnat.h"
#include "luku.h"

#include <stdlib.h>
#include <string.h>

/* Function to create a new Kunta object. */
Kunta *luoKunta(const char *nimi, unsigned int vakiluku, float pintaala) {
  Kunta *k;
  char *nimiKopio;
  size_t len;

  if (nimi == NULL) {
    return NULL;
  }

  k = malloc(sizeof(Kunta));
  if (k == NULL) {
    return NULL;
  }

  len = strlen(nimi);

  nimiKopio = malloc((len + 1) * sizeof(char));
  if (nimiKopio == NULL) {
    free(k);
    return NULL;
  }

  strcpy(nimiKopio, nimi);

  k->nimi = nimiKopio;
  k->vakiluku = vakiluku;
  k->pintaala = pintaala;

  return k;
}

/* Function to free the memory allocated for a Kunta object. */
void tuhoaKunta(Kunta *k) {
  if (k == NULL) {
    return;
  }

  free((char *)k->nimi);
  free(k);
}

/* Helper function to parse a line of input and create a Kunta object. */
static int kasittele_rivi(char *rivi, Kunta **uusi) {
  char *nimi;
  char *pintaalaStr;
  char *vakilukuStr;
  char *loppu;
  float pintaala;
  unsigned int vakiluku;

  *uusi = NULL;

  nimi = strtok(rivi, ";");
  pintaalaStr = strtok(NULL, ";");
  vakilukuStr = strtok(NULL, ";");

  if (nimi == NULL || pintaalaStr == NULL || vakilukuStr == NULL) {
    return 0;
  }

  if (nimi[0] != '"') {
    return 0;
  }

  loppu = strrchr(nimi, '"');
  if (loppu == NULL || loppu == nimi) {
    return 0;
  }

  *loppu = '\0';

  if (sscanf(pintaalaStr, "%f", &pintaala) != 1) {
    return 0;
  }

  if (sscanf(vakilukuStr, "%u", &vakiluku) != 1) {
    return 0;
  }

  *uusi = luoKunta(nimi + 1, vakiluku, pintaala);

  if (*uusi == NULL) {
    return 0;
  }

  return 1;
}

/* Function to read municipalities from a file and return an array of pointers
 * to Kunta objects. */
Kunta **lueKunnat(FILE *in, size_t *count) {
  Kunta **kunnat;
  Kunta **tmp;
  Kunta *uusi;
  size_t cap;
  size_t lkm;
  size_t len;
  char *rivi;

  cap = 1;
  lkm = 0;

  kunnat = malloc(cap * sizeof(Kunta *));
  if (kunnat == NULL) {
    if (count != NULL) {
      *count = 0;
    }
    return NULL;
  }

  while ((rivi = lueKunnes(in, '\n', &len)) != NULL) {
    if (!kasittele_rivi(rivi, &uusi)) {
      free(rivi);
      break;
    }

    if (lkm == cap) {
      cap = cap * 2;

      tmp = realloc(kunnat, cap * sizeof(Kunta *));
      if (tmp == NULL) {
        tuhoaKunta(uusi);
        free(rivi);

        while (lkm > 0) {
          lkm--;
          tuhoaKunta(kunnat[lkm]);
        }

        free(kunnat);

        if (count != NULL) {
          *count = 0;
        }

        return NULL;
      }

      kunnat = tmp;
    }

    kunnat[lkm] = uusi;
    lkm++;

    free(rivi);
  }

  tmp = realloc(kunnat, lkm * sizeof(Kunta *));
  if (tmp != NULL || lkm == 0) {
    kunnat = tmp;
  }

  if (count != NULL) {
    *count = lkm;
  }

  return kunnat;
}
