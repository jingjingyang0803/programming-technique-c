#include "ykkosvalit.h"

#include <stdio.h>

/* Function to tidy spaces in a file */
UintPari ykkosValit(const char *inputFN, const char *outputFN) {
  FILE *in;
  FILE *out;
  UintPari tulos;
  int c;
  int rivin_alussa;
  int odottaa_valia;

  tulos.x = 0;
  tulos.y = 0;

  in = fopen(inputFN, "r");
  if (in == NULL) {
    return tulos;
  }

  out = fopen(outputFN, "w");
  if (out == NULL) {
    fclose(in);
    return tulos;
  }

  rivin_alussa = 1;
  odottaa_valia = 0;

  while ((c = fgetc(in)) != EOF) {
    tulos.x++;

    if (c == ' ') {
      if (!rivin_alussa) {
        odottaa_valia = 1;
      }
    } else if (c == '\n') {
      odottaa_valia = 0;
      fputc(c, out);
      tulos.y++;
      rivin_alussa = 1;
    } else {
      if (odottaa_valia) {
        fputc(' ', out);
        tulos.y++;
        odottaa_valia = 0;
      }

      fputc(c, out);
      tulos.y++;
      rivin_alussa = 0;
    }
  }

  fclose(in);
  fclose(out);

  return tulos;
}
