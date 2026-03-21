/*
EXERCISE: Geometria

Print the value of the constant PII to 19 decimal places.
Converts each received command line parameter to a double value r.
And prints area, volume and circumference to 10 decimal places.
*/
#include "geometria.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;

  printf("Piin arvo: %.19Lf\n", PII);

  for (i = 1; i < argc; i++) {
    double r = atof(argv[i]);
    printf("Säteen %f omaavan ympyrän ala ja pallon tilavuus: %.10f ja %.10f\n",
           r, ympyranAla(r), pallonTilavuus(r));
    printf("Säteen %f omaavan ympyrän piiri on %.10Lf\n", r, 2 * PII * r);
  }

  return 0;
}