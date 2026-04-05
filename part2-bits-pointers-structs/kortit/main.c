#include "kortit.h"
#include <stdio.h>

int main(void) {
  Kortti pakka[KORTTI_LKM]; /* pakka = deck in Finnish */
  int i = 0;
  Maa m;
  Arvo a;
  for (m = HERTTA; m <= PATA; ++m) /* Iterate over all suits. */
  {
    for (a = ASSA; a <= KUNKKU; ++a) /* Iterate over all ranks. */
    {
      pakka[i].maa = m;
      pakka[i].arvo = a;
      if (i % MAA_KOKO) /* Output a space or a new line before the card? */
      {
        printf("%c", ((i % 4) == 0) ? '\n' : ' ');
      }
      if (i % 2) { /* Even cards are printed using a value parameter... */
        tulostaKortti(pakka[i]);
      } else { /* ... and odd cards using pointer parameter. */
        tulostaKorttiOs(&pakka[i]);
      }
      i += 1; /* move to the next card within the deck. */
    }
    printf("\n"); /* A new line after each suit. */
  }
  return 0;
}
