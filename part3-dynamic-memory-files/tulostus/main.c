/*
This program demonstrates how to use dynamic memory allocation to create an
array of doubles, fill it with values, and then print those values to a file
using a function defined in a separate header file.
The program takes command-line arguments to specify the size of the array, the
name of the array, the precision for printing, and the filename to which the
output should be written.
*/

#include "tulostus.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc == 5) {
    int count = atoi(argv[1]);
    double *t = malloc(count * sizeof(double));
    int i = 0;
    for (i = 1; i <= count; ++i) {
      t[i - 1] = (double)i / 16;
    }
    tulostaDblTaulu(t, count, argv[2], atoi(argv[3]), argv[4]);
  }
  return 0;
}
