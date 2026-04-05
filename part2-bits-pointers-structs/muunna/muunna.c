#include "muunna.h"

void muunnaTaulu(unsigned int size, double *array, TransformFunc trans) {
  unsigned int i;
  for (i = 0; i < size; ++i) {
    array[i] = trans(array[i]);
  }
}
