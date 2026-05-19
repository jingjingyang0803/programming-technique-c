/*
This program demonstrates the use of a linked list data structure defined in the
"lista.h" header file. The program creates a linked list that stores integers,
adds multiple integers to the list using the ll_moniLisaa function, and prints
the contents of the list after each insertion. The integers added to the list
are multiplied by 10 in each iteration to show the changes in the list. Finally,
the program frees the memory allocated for the list before exiting.

Expected output:
    Solmussa s on arvo 1
    Lista: 1 2 3 4
    Solmussa s on arvo 10
    Lista: 1 2 10 20 30 40 3 4
    Solmussa s on arvo 100
    Lista: 1 2 10 20 100 200 300 400 30 40 3 4
    Solmussa s on arvo 1000
    Lista: 1 2 10 20 100 200 1000 2000 3000 4000 300 400 30 40 3 4
*/

#include "lista.h"
#include <stdio.h>

static void
tulostaInt(FILE *virta,
           const void *arvo) { /* Outputs the value pointed to by arvo as an int
                                  into the output stream virta. */
  const int *intOsoitin = arvo;
  fprintf(virta, "%d", *intOsoitin);
}

int main(void) {
  int i = 0, j = 0;
  int it[4] = {1, 2, 3, 4}; /* Values to insert. */
  Lista *ll = ll_luo(sizeof(int), tulostaInt);
  Solmu *s = NULL;
  for (i = 0; i < 4; ++i) {
    s = ll_moniLisaa(ll, ll->n / 2, &it[0], &it[1], &it[2], &it[3], NULL);
    printf("Solmussa s on arvo %d\n", *((int *)s->data));
    ll_tulosta(ll, stdout);
    for (j = 0; j < 4; ++j) {
      it[j] *= 10; /* Multiply each added value by 10 for the next round. */
    }
  }
  ll_tuhoa(ll);
  return 0;
}
