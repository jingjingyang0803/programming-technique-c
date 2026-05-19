#include "yhdista.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *yhdista(const char *mj, ...) {
  va_list ap;
  const char *s;
  char *tulos;
  char *kohta;
  size_t pituus;

  pituus = 0;

  va_start(ap, mj);

  s = mj;
  while (s != NULL) {
    pituus += strlen(s);
    s = va_arg(ap, const char *);
  }

  va_end(ap);

  tulos = malloc(pituus + 1);
  if (tulos == NULL) {
    return NULL;
  }

  kohta = tulos;

  va_start(ap, mj);

  s = mj;
  while (s != NULL) {
    size_t len;

    len = strlen(s);
    memcpy(kohta, s, len);
    kohta += len;

    s = va_arg(ap, const char *);
  }

  va_end(ap);

  *kohta = '\0';

  return tulos;
}
