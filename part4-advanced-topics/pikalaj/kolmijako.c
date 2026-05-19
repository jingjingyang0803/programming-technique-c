#include "kolmijako.h"

static void vaihda(int *a, int *b) {
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

IntPari kolmijako(unsigned int koko, int taulu[], int vipu1, int vipu2, int *p1,
                  int *p2) {
  unsigned int i;
  int vasen;
  int oikea;
  int pivot1;
  int pivot2;
  IntPari tulos;

  if (koko <= 1) {
    *p1 = 0;
    *p2 = 0;
    tulos.x = 0;
    tulos.y = 0;
    return tulos;
  }

  if (taulu[vipu1] > taulu[vipu2]) {
    vaihda(&taulu[vipu1], &taulu[vipu2]);
  }

  vaihda(&taulu[0], &taulu[vipu1]);
  vaihda(&taulu[koko - 1], &taulu[vipu2]);

  pivot1 = taulu[0];
  pivot2 = taulu[koko - 1];

  vasen = 1;
  oikea = (int)koko - 2;
  i = 1;

  while ((int)i <= oikea) {
    if (taulu[i] < pivot1) {
      vaihda(&taulu[i], &taulu[vasen]);
      vasen++;
      i++;
    } else if (taulu[i] > pivot2) {
      vaihda(&taulu[i], &taulu[oikea]);
      oikea--;
    } else {
      i++;
    }
  }

  vasen--;
  oikea++;

  vaihda(&taulu[0], &taulu[vasen]);
  vaihda(&taulu[koko - 1], &taulu[oikea]);

  *p1 = vasen;
  *p2 = oikea;

  tulos.x = vasen;
  tulos.y = oikea;

  return tulos;
}
