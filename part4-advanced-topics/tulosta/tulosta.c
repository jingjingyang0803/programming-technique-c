#include "tulosta.h"

#include <stdarg.h>

/* Helper function to print a single character and return the number of
 * characters printed. */
static size_t tulostaMerkki(FILE *td, char c) {
  fputc(c, td);
  return 1;
}

/* Helper function to print a string and return the number of characters
 * printed. */
static size_t tulostaMerkkijono(FILE *td, const char *s) {
  size_t n;

  n = 0;

  while (*s != '\0') {
    fputc(*s, td);
    ++n;
    ++s;
  }

  return n;
}

/* Helper function to print an integer and return the number of characters
 * printed. */
static size_t tulostaLuku(FILE *td, int luku) {
  char numerot[20];
  int i;
  unsigned int x;
  size_t n;

  n = 0;

  if (luku < 0) {
    fputc('-', td);
    ++n;
    x = (unsigned int)(-(luku + 1)) + 1;
  } else {
    x = (unsigned int)luku;
  }

  if (x == 0) {
    fputc('0', td);
    return n + 1;
  }

  i = 0;

  while (x > 0) {
    numerot[i] = (char)('0' + (x % 10));
    x /= 10;
    ++i;
  }

  while (i > 0) {
    --i;
    fputc(numerot[i], td);
    ++n;
  }

  return n;
}

/* Main function to print formatted output based on the format string and
 * variable arguments. */
size_t tulosta(FILE *td, const char *mj, ...) {
  va_list ap;
  size_t n;
  int i;

  n = 0;
  i = 0;

  va_start(ap, mj);

  while (mj[i] != '\0') {
    if (mj[i] != '%') {
      n += tulostaMerkki(td, mj[i]);
    } else {
      ++i;

      if (mj[i] == '%') {
        n += tulostaMerkki(td, '%');
      } else if (mj[i] == 'd') {
        n += tulostaLuku(td, va_arg(ap, int));
      } else if (mj[i] == 's') {
        n += tulostaMerkkijono(td, va_arg(ap, char *));
      } else if (mj[i] == 'c') {
        n += tulostaMerkki(td, (char)va_arg(ap, int));
      }
    }

    ++i;
  }

  va_end(ap);

  return n;
}
