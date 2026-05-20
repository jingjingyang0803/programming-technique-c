#include "rivisanat.h"
#include "luku.h"

#include <stdlib.h>
#include <string.h>

/* Helper function to copy a string. */
static char *kopioi_sana(const char *s) {
  char *uusi;
  size_t len;

  len = strlen(s);

  uusi = malloc((len + 1) * sizeof(char));
  if (uusi == NULL) {
    return NULL;
  }

  strcpy(uusi, s);
  return uusi;
}

/* Function to free the memory allocated for RiviSanat structure. */
void tuhoaRiviSanat(RiviSanat *rs) {
  size_t i;
  size_t j;

  if (rs == NULL) {
    return;
  }

  if (rs->rivit != NULL) {
    for (i = 0; i < rs->riviLkm; i++) {
      if (rs->rivit[i] != NULL) {
        for (j = 0; j < rs->riviKoot[i]; j++) {
          free(rs->rivit[i][j]);
        }
        free(rs->rivit[i]);
      }
    }
    free(rs->rivit);
  }

  free(rs->riviKoot);
  free(rs);
}

/* Function to read lines from a file and tokenize them into words. */
RiviSanat *lueRiviSanat(FILE *is) {
  RiviSanat *rs;
  size_t cap;
  size_t lineCap;
  size_t len;
  char *rivi;
  char *sana;
  char *sanaKopio;
  char ***uudetRivit;
  size_t *uudetKoot;
  char **uudetSanat;

  cap = 1;

  rs = malloc(sizeof(RiviSanat));
  if (rs == NULL) {
    return NULL;
  }

  rs->rivit = malloc(cap * sizeof(char **));
  rs->riviKoot = malloc(cap * sizeof(size_t));
  rs->riviLkm = 0;

  if (rs->rivit == NULL || rs->riviKoot == NULL) {
    tuhoaRiviSanat(rs);
    return NULL;
  }

  while ((rivi = lueKunnes(is, '\n', &len)) != NULL) {
    if (rs->riviLkm == cap) {
      cap = cap * 2;

      uudetRivit = realloc(rs->rivit, cap * sizeof(char **));
      if (uudetRivit == NULL) {
        free(rivi);
        tuhoaRiviSanat(rs);
        return NULL;
      }
      rs->rivit = uudetRivit;

      uudetKoot = realloc(rs->riviKoot, cap * sizeof(size_t));
      if (uudetKoot == NULL) {
        free(rivi);
        tuhoaRiviSanat(rs);
        return NULL;
      }
      rs->riviKoot = uudetKoot;
    }

    rs->riviKoot[rs->riviLkm] = 0;
    lineCap = 1;

    rs->rivit[rs->riviLkm] = malloc(lineCap * sizeof(char *));
    if (rs->rivit[rs->riviLkm] == NULL) {
      free(rivi);
      tuhoaRiviSanat(rs);
      return NULL;
    }

    sana = strtok(rivi, " ");

    while (sana != NULL) {
      if (rs->riviKoot[rs->riviLkm] == lineCap) {
        lineCap = lineCap * 2;

        uudetSanat = realloc(rs->rivit[rs->riviLkm], lineCap * sizeof(char *));
        if (uudetSanat == NULL) {
          free(rivi);
          tuhoaRiviSanat(rs);
          return NULL;
        }

        rs->rivit[rs->riviLkm] = uudetSanat;
      }

      sanaKopio = kopioi_sana(sana);
      if (sanaKopio == NULL) {
        free(rivi);
        tuhoaRiviSanat(rs);
        return NULL;
      }

      rs->rivit[rs->riviLkm][rs->riviKoot[rs->riviLkm]] = sanaKopio;
      rs->riviKoot[rs->riviLkm]++;

      sana = strtok(NULL, " ");
    }

    uudetSanat = realloc(rs->rivit[rs->riviLkm],
                         rs->riviKoot[rs->riviLkm] * sizeof(char *));
    rs->rivit[rs->riviLkm] = uudetSanat;

    rs->riviLkm++;

    free(rivi);
  }

  uudetRivit = realloc(rs->rivit, rs->riviLkm * sizeof(char **));
  rs->rivit = uudetRivit;

  uudetKoot = realloc(rs->riviKoot, rs->riviLkm * sizeof(size_t));
  rs->riviKoot = uudetKoot;

  return rs;
}
