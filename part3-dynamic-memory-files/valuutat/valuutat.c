/*
EXERCISE: Currency exchange rates

Write a program that allows the user to enter currency exchange rates and
convert amounts between different currencies. The program should support the
following commands:
    - "kurssi <valuutta> <kurssi>": Set the exchange rate for a currency. The
    exchange rate is the value of one unit of the currency in euros.
    - "muunna <amount> <valuutta>": Convert the given amount from the specified
    currency to euros and print the result.
    - "kurssit": Print the exchange rates for all currencies in sorted order.
    - "lopeta": Exit the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nimi[4];
  double kurssi;
} Valuutta;

static int vertaa_valuuttaa(const void *a, const void *b) {
  const Valuutta *x;
  const Valuutta *y;

  x = (const Valuutta *)a;
  y = (const Valuutta *)b;

  return strcmp(x->nimi, y->nimi);
}

static int etsi_valuutta(Valuutta *valuutat, size_t lkm, const char *nimi) {
  size_t i;

  for (i = 0; i < lkm; i++) {
    if (strcmp(valuutat[i].nimi, nimi) == 0) {
      return (int)i;
    }
  }

  return -1;
}

int main(void) {
  Valuutta *valuutat;
  size_t lkm;
  size_t koko;
  char rivi[81];
  char komento[16];
  char nimi[4];
  double arvo;
  int paikka;
  size_t i;

  valuutat = NULL;
  lkm = 0;
  koko = 0;

  while (fgets(rivi, sizeof(rivi), stdin) != NULL) {
    if (sscanf(rivi, "%15s", komento) != 1) {
      continue;
    }

    if (strcmp(komento, "lopeta") == 0) {
      break;
    }

    if (strcmp(komento, "kurssi") == 0) {
      if (sscanf(rivi, "%15s %3s %lf", komento, nimi, &arvo) == 3) {
        paikka = etsi_valuutta(valuutat, lkm, nimi);

        if (paikka >= 0) {
          valuutat[paikka].kurssi = arvo;
        } else {
          if (lkm == koko) {
            size_t uusi_koko;
            Valuutta *uusi;

            if (koko == 0) {
              uusi_koko = 2;
            } else {
              uusi_koko = 2 * koko;
            }

            uusi = realloc(valuutat, uusi_koko * sizeof(Valuutta));
            if (uusi == NULL) {
              free(valuutat);
              return 1;
            }

            valuutat = uusi;
            koko = uusi_koko;
          }

          strcpy(valuutat[lkm].nimi, nimi);
          valuutat[lkm].kurssi = arvo;
          lkm++;
        }
      }
    } else if (strcmp(komento, "muunna") == 0) {
      if (sscanf(rivi, "%15s %lf %3s", komento, &arvo, nimi) == 3) {
        paikka = etsi_valuutta(valuutat, lkm, nimi);

        if (paikka >= 0) {
          printf("%.3f %s = %.3f EUR\n", arvo, nimi,
                 arvo / valuutat[paikka].kurssi);
        } else {
          printf("Valuutan %s kurssia ei ole tiedossa!\n", nimi);
        }
      }
    } else if (strcmp(komento, "kurssit") == 0) {
      qsort(valuutat, lkm, sizeof(Valuutta), vertaa_valuuttaa);

      for (i = 0; i < lkm; i++) {
        printf("%s %.3f\n", valuutat[i].nimi, valuutat[i].kurssi);
      }
    }
  }

  free(valuutat);

  return 0;
}
