/*
This program demonstrates the use of a custom printing function called
`tulosta`. The `tulosta` function takes a variable number of arguments and
prints them to a specified output stream according to a format string.

The program prints "Hello World" followed by the number of characters printed,
and then prints "Ja sitten" followed by the number of characters printed again.
Finally, it prints the total number of characters printed.

Expected output:
    Hello World%
    Tulostui 13 merkkiä
    Ja sitten 21 merkkiä
    Tulostui 22 merkkiä
*/
#include "tulosta.h"

int main(void) {
  size_t pit;

  pit = tulosta(stdout, "%s%%\n", "Hello World");
  pit = tulosta(stdout, "Tulostui %d merkkiä\n", (int)pit);
  pit = tulosta(stdout, "%c%c sitten %d merkkiä\n", 'J', 'a', (int)pit);
  tulosta(stdout, "Tulostui %d merkkiä\n", (int)pit);

  return 0;
}
