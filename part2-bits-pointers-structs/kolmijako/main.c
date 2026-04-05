#include "kolmijako.h"
#include <stdio.h>

int main(void) {
  int t[7] = {1, 7, 4, 5, 2, 8, 9};
  int x = 0; /* Will receive less1 via a pointer parameter. */
  int y = 0; /* Will receive less2 via a pointer parameter. */
  /* IntPari object ip receives less1 and less2 from the return value. */
  IntPari ip = kolmijako(7, t, 4, 1, &x, &y);
  int i = 0;
  /* Output both versions of less1 and less2 (pienet1 and pienet2 in Finnish).
   */
  printf("pienet1: %d ja %d\npienet2: %d ja %d\n", x, ip.x, y, ip.y);
  for (i = 0; i < 7; ++i) { /* Verify that each value is in a legal position
                               with respect to the pivots 2 and 7. */
    if (((i < x) && (t[i] >= 2)) || ((i < y) && (t[i] >= 7))) {
      printf("Alkioiden järjestys laiton\n"); /* A value was in an illegal
                                                 position! */
      break;
    }
  }
  return 0;
}
