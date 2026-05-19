#include "lista.h"
#include <stdio.h>

static void tulostaInt(FILE *virta,
                       const void *arvo) { /* Prints the pointed int value to
                                              the output stream virta. */
  const int *intOsoitin = arvo;
  fprintf(virta, "%d", *intOsoitin);
}

int main(void) {
  int i = 0;
  int arvoja[5] = {2, 8, 1, 7, 4};
  Lista *ll = ll_luo(sizeof(int), tulostaInt); /* Alkion koko: sizeof(int). */
  for (i = 0; i < 5; ++i) { /* Pass each arvoja[i] via a pointer. */
    ll_lisaaEteen(ll, &arvoja[i]);
  }
  ll_tulosta(ll, stdout);
  for (i = 0; i < 5; ++i) { /* Pass each i via a pointer. */
    ll_lisaaEteen(ll, &i);
  }
  ll_tulosta(ll, stdout);
  ll_tuhoa(ll);
  return 0;
}
