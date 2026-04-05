#include "asteet.h"
#include <stdio.h>

int main(void) {
  Lampotila a = {23.5, Celsius};
  Lampotila b = {79.7, Fahrenheit};
  Lampotila c = {285.8, Kelvin};
  Asteikko kelvin = Kelvin;
  printf("23.5 C on %.2f K\n",
         muunna(a, kelvin)); /* Uses the above defined enum variable kelvin. */
  printf("79.7 F on %.2f C\n", muunna(b, Celsius));
  printf("285.8 K - 79.7 F on %.2f C\n", erotus(c, b, Celsius));

  return 0;
}
