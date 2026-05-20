#include "luku.h"

#include <stdlib.h>

/* Function to read a line of input until a delimiter is found. */
char *lueKunnes(FILE *instream, char delim, size_t *n) {
  char *buf;
  char *tmp;
  size_t cap;
  size_t len;
  int c;
  int loytyi_delim;

  cap = 1;
  len = 0;
  loytyi_delim = 0;

  buf = malloc(cap);
  if (buf == NULL) {
    if (n != NULL) {
      *n = 0;
    }
    return NULL;
  }

  while ((c = fgetc(instream)) != EOF) {
    if (c == (unsigned char)delim) {
      loytyi_delim = 1;
      break;
    }

    if (len == cap) {
      cap = cap * 2;
      tmp = realloc(buf, cap);
      if (tmp == NULL) {
        free(buf);
        if (n != NULL) {
          *n = 0;
        }
        return NULL;
      }
      buf = tmp;
    }

    buf[len] = (char)c;
    len++;
  }

  if (len > 0 || loytyi_delim) {
    tmp = realloc(buf, len + 1);
    if (tmp == NULL) {
      free(buf);
      if (n != NULL) {
        *n = 0;
      }
      return NULL;
    }

    buf = tmp;
    buf[len] = '\0';
  } else {
    tmp = realloc(buf, 0);
    (void)tmp;
    buf = NULL;
  }

  if (n != NULL) {
    *n = len;
  }

  return buf;
}
