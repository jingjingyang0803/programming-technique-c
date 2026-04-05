#include "piste3d.h"
#include <math.h>
#include <stdio.h>

int main(void) {
  Piste3D points[3] = {{1.0, 2.5, -4.0}, {-1.0, -3.5, -7.0}, {4.5, -0.5, 1.5}};
  int i = 0;
  int j = 0;
  int prec = 1;
  for (i = 0; i < 3; ++i) {
    for (j = i + 1; j < 3; ++j) {
      printf("Pisteiden ");
      tulosta(points[i], prec);
      printf(" ja ");
      tulosta(points[j], prec++);
      printf(" etäisyys: %.3f\n", etaisyys(points[i], points[j]));
    }
  }
  return 0;
}
