#include "piste3d.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void tulosta(Piste3D p, int prec) {
  printf("(%.*f, %.*f, %.*f)", prec, p.x, prec, p.y, prec, p.z);
}

double etaisyys(Piste3D p1, Piste3D p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  double dz = p1.z - p2.z;
  return sqrt(dx * dx + dy * dy + dz * dz);
}
