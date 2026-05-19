/*
This program demonstrates how to handle signals in C. It uses the setjmp and
longjmp functions to handle the signals. The program reads commands from the
standard input and performs the corresponding actions. If a command causes a
SIGFPE or SIGSEGV signal to be raised, the program will handle the signal and
continue execution.
*/
#include "signaalit.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char rivi[100];
  int *taulukko = NULL;
  unsigned int maara = 0;
  unsigned int koko = 0;

  signal(SIGFPE, hoidaSIGFPE);
  signal(SIGSEGV, hoidaSIGSEGV);

  while (fgets(rivi, sizeof(rivi), stdin) != NULL) {
    switch (setjmp(paluuTila)) {
    case 0: {
      int a;
      int b;
      int tulos;
      unsigned int i;
      unsigned int j;
      unsigned int uusiKoko;
      int *uusi;

      if (sscanf(rivi, "lisää %d %d", &a, &b) == 2) {
        if (b == 0) {
          hoidaSIGFPE(SIGFPE);
        }

        tulos = a / b;

        if (maara >= koko) {
          if (koko == 0) {
            uusiKoko = 4;
          } else {
            uusiKoko = koko * 2;
          }

          uusi = realloc(taulukko, uusiKoko * sizeof(int));
          if (uusi == NULL) {
            free(taulukko);
            return 1;
          }

          taulukko = uusi;
          koko = uusiKoko;
        }

        taulukko[maara] = tulos;
        maara++;
      } else if (sscanf(rivi, "tulosta %u", &i) == 1) {
        if (i >= maara) {
          hoidaSIGSEGV(SIGSEGV);
        }

        printf("%d\n", taulukko[i]);
      } else if (strcmp(rivi, "tulosta\n") == 0 ||
                 strcmp(rivi, "tulosta") == 0) {
        for (j = 0; j < maara; j++) {
          if (j > 0) {
            printf(" ");
          }
          printf("%d", taulukko[j]);
        }
        printf("\n");
      } else {
        free(taulukko);
        return 0;
      }

      break;
    }

    case SIGFPE:
      printf("Aiheutui signaali SIGFPE\n");
      break;

    case SIGSEGV:
      printf("Aiheutui signaali SIGSEGV\n");
      break;

    default:
      printf("Aiheutui signaali UNKNOWN\n");
      break;
    }
  }

  free(taulukko);
  return 0;
}
