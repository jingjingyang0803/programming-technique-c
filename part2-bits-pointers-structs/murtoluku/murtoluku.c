#include "murtoluku.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Murtoluku supistettuML(int os, int nim) {
  Murtoluku mlt;
  int aos, anim;
  int i = 2;

  if (nim == 0) { /* Avoid division by zero. */
    mlt.os = os;
    mlt.nim = nim;
    return mlt;
  }
  aos = abs(os);
  anim = abs(nim);
  /* Reduce the fraction by dividing both the numerator and denominator by their
   * common factors continuously. */
  while (i <= aos && i <= anim) {
    /* If both the numerator and denominator are divisible by i, divide them by
     * i. */
    if (aos % i == 0 && anim % i == 0) {
      aos /= i;
      anim /= i;
    } else {
      ++i;
    }
  }

  mlt.os = aos;
  mlt.nim = anim;
  if (os * nim <
      0) { /* If the fraction is negative, make the numerator negative. */
    mlt.os = -mlt.os;
  }

  return mlt;
}

void tulostaML(Murtoluku m) {
  if (m.nim == 0) {
    printf("Undefined (denominator is zero)");
  } else if (m.os == 0) { /* If the numerator is zero, print only zero. */
    printf("0");
  } else if (m.nim ==
             1) { /* If the denominator is 1, print only the numerator. */
    printf("%d", m.os);
  } else {
    printf("%d/%d", m.os, m.nim);
  }
}

Murtoluku lisaaML(Murtoluku a, Murtoluku b) {
  return supistettuML(a.os * b.nim + b.os * a.nim, a.nim * b.nim);
}

Murtoluku vahennaML(Murtoluku a, Murtoluku b) {
  return supistettuML(a.os * b.nim - b.os * a.nim, a.nim * b.nim);
}

Murtoluku kerroML(Murtoluku a, Murtoluku b) {
  return supistettuML(a.os * b.os, a.nim * b.nim);
}

Murtoluku jaaML(Murtoluku a, Murtoluku b) {
  return supistettuML(a.os * b.nim, a.nim * b.os);
}
