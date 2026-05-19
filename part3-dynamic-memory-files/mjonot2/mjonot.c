#include "mjonot.h"
#include <stdlib.h>
#include <string.h>

static char *kopioi_mjono(const char *s) {
  char *uusi;
  size_t len;

  len = strlen(s);

  uusi = malloc((len + 1) * sizeof(char));
  if (uusi == NULL) {
    return NULL;
  }

  strcpy(uusi, s);

  return uusi;
}

char **jarjesta_mjt(char **strs, size_t n,
                    int (*cmp)(const char *, const char *)) {
  char **kopio;
  char *apu;
  size_t i;
  size_t j;

  kopio = malloc(n * sizeof(char *));
  if (kopio == NULL) {
    return NULL;
  }

  for (i = 0; i < n; i++) {
    kopio[i] = kopioi_mjono(strs[i]);

    if (kopio[i] == NULL) {
      while (i > 0) {
        i--;
        free(kopio[i]);
      }

      free(kopio);
      return NULL;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (cmp(kopio[j], kopio[i])) {
        apu = kopio[i];
        kopio[i] = kopio[j];
        kopio[j] = apu;
      }
    }
  }

  return kopio;
}
