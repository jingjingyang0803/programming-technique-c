/*
This program demonstrates the use of macros in C. It defines several macros for
calculating the minimum and maximum of two, three, or four values, as well as a
macro for the value of pi. The program takes four floating-point numbers as
input from the command line and uses the macros to calculate and display the
minimum and maximum values among them.
*/

#include "makro.h"
#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char *argv[]) {
  TYYPPI s, t, u, v;
  int d;

  if (agrc != 5) {
    fprintf(stderr, "Usage: %s <s> <t> <u> <v>\n", argv[0]);
    return 1;
  }
  s = atof(argv[1]);
  t = atof(argv[2]);
  u = atof(argv[3]);
  v = atof(argv[4]);
  d = DESIMAALIT; /* Use d as a "shorthand" for DESIMAALIT... */
  /* Note: C compiler concatenates successive string literals. */
  /* E.g. the three strings "one" " and " "two" become "one and two". */
  debug("Pii: " MJ(PII) "\n");
  printf("Arvojen %.*f ja %.*f minimi ja maksimi: %.*f ja %.*f\n", d, (double)s,
         d, (double)t, d, (double)MIN(s, t), d, (double)MAX(s, t));
  printf("Arvojen %.*f, %.*f, ja %.*f minimi ja maksimi: %.*f ja %.*f\n", d,
         (double)t, d, (double)u, d, (double)v, d, (double)MIN3(t, u, v), d,
         (double)MAX3(t, u, v));
  printf("Arvojen %.*f, %.*f, %.*f ja %.*f minimi ja maksimi: %.*f ja %.*f\n",
         d, (double)s, d, (double)t, d, (double)u, d, (double)v, d,
         (double)MIN4(s, t, u, v), d, (double)MAX4(s, t, u, v));
  return 0;
}
