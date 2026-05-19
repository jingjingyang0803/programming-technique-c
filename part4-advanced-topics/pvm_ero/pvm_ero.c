#include "pvm_ero.h"

#include <ctype.h>
#include <stdio.h>
#include <time.h>

/* Helper function to read a number from a string. */
static int lue_numero(const char **s, int min, int max, int *arvo) {
  int n;
  int v;

  n = 0;
  v = 0;

  while (isdigit((unsigned char)**s) && n < max) {
    v = v * 10 + (**s - '0');
    (*s)++;
    n++;
  }

  if (n < min) {
    return 0;
  }

  if (isdigit((unsigned char)**s)) {
    return 0;
  }

  *arvo = v;
  return 1;
}

/* Helper function to read a date from a string and convert it to time_t. */
static int lue_pvm(const char *s, struct tm *pvm, time_t *aika) {
  int paiva;
  int kuukausi;
  int vuosi;
  struct tm tarkistus;

  if (!lue_numero(&s, 1, 2, &paiva)) {
    return 0;
  }

  if (*s != '.') {
    return 0;
  }
  s++;

  if (!lue_numero(&s, 1, 2, &kuukausi)) {
    return 0;
  }

  if (*s != '.') {
    return 0;
  }
  s++;

  if (!lue_numero(&s, 4, 4, &vuosi)) {
    return 0;
  }

  if (*s != '\0') {
    return 0;
  }

  tarkistus.tm_sec = 0;
  tarkistus.tm_min = 0;
  tarkistus.tm_hour = 12;
  tarkistus.tm_mday = paiva;
  tarkistus.tm_mon = kuukausi - 1;
  tarkistus.tm_year = vuosi - 1900;
  tarkistus.tm_wday = 0;
  tarkistus.tm_yday = 0;
  tarkistus.tm_isdst = 0;

  *aika = mktime(&tarkistus);

  if (*aika == (time_t)-1) {
    return 0;
  }

  if (tarkistus.tm_mday != paiva || tarkistus.tm_mon != kuukausi - 1 ||
      tarkistus.tm_year != vuosi - 1900) {
    return 0;
  }

  *pvm = tarkistus;
  return 1;
}

/* Main function to calculate the difference in days between two dates. */
void pvm_ero(const char *pvm1, const char *pvm2) {
  struct tm tm1;
  struct tm tm2;
  struct tm alku;
  struct tm loppu;
  time_t aika1;
  time_t aika2;
  time_t alkuAika;
  time_t loppuAika;
  long paivia;
  const char *paivat[] = {"sunnuntai", "maanantai", "tiistai", "keskiviikko",
                          "torstai",   "perjantai", "lauantai"};

  if (!lue_pvm(pvm1, &tm1, &aika1) || !lue_pvm(pvm2, &tm2, &aika2)) {
    fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
    return;
  }

  if (difftime(aika1, aika2) <= 0) {
    alku = tm1;
    loppu = tm2;
    alkuAika = aika1;
    loppuAika = aika2;
  } else {
    alku = tm2;
    loppu = tm1;
    alkuAika = aika2;
    loppuAika = aika1;
  }

  paivia = (long)(difftime(loppuAika, alkuAika) / (60 * 60 * 24)) + 1;

  printf("%s %02d.%02d.%04d --> %s %02d.%02d.%04d: yhteensä %ld päivää\n",
         paivat[alku.tm_wday], alku.tm_mday, alku.tm_mon + 1,
         alku.tm_year + 1900, paivat[loppu.tm_wday], loppu.tm_mday,
         loppu.tm_mon + 1, loppu.tm_year + 1900, paivia);
}
