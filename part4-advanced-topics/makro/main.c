/*
This program demonstrates the use of macros in C. It defines macros for
calculating the minimum and maximum of two, three, or four values, a macro for
the value of pi, a macro for converting a macro value into a string, and a debug
macro.

The program takes four floating-point numbers as command-line arguments and uses
the macros to calculate and display the minimum and maximum values among them.

If the program is compiled with -DOTE_DEBUG, the debug macro prints the value of
pi to stderr. If OTE_DEBUG is omitted, the debug macro expands to nothing, so
the value of pi is not printed.

If the program is compiled with -DDESIMAALIT=n, n is used as the number of
decimal places in the output. If DESIMAALIT is omitted, it defaults to 3.

If the program is compiled with -DTYYPPI=float, the variables s, t, u, and v use
the float type. If it is compiled with -DTYYPPI=double, they use the double
type. If TYYPPI is omitted, it defaults to unsigned char. In that case, values
are converted to unsigned char; for example, 150.2 may be shown as 150, and
-10.8 may be shown as 246 on systems where unsigned char represents values from
0 to 255.
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
