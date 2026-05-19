#include "kertotaulu.h"
#include <stdio.h>
#include <stdlib.h>

static uint num_width(uint x) {
  uint w;

  w = 1;

  while (x >= 10) {
    x = x / 10;
    w++;
  }

  return w;
}

char **luo_kertotaulu_mjt(uint a, uint b, uint c, uint d) {
  uint cols;
  uint rows_count;
  uint *widths;
  char **rows;
  uint row_len;
  uint i;
  uint j;
  uint k;
  uint value;

  cols = b - a + 2;
  rows_count = d - c + 2;

  widths = malloc(cols * sizeof(uint));
  if (widths == NULL) {
    return NULL;
  }

  widths[0] = num_width(d);

  for (j = 1; j < cols; j++) {
    widths[j] = num_width(d * (a + j - 1));
  }

  row_len = 0;
  for (j = 0; j < cols; j++) {
    row_len = row_len + widths[j];
  }
  row_len = row_len + cols - 1;

  rows = malloc(rows_count * sizeof(char *));
  if (rows == NULL) {
    free(widths);
    return NULL;
  }

  for (i = 0; i < rows_count; i++) {
    rows[i] = malloc((row_len + 1) * sizeof(char));

    if (rows[i] == NULL) {
      while (i > 0) {
        i--;
        free(rows[i]);
      }

      free(rows);
      free(widths);
      return NULL;
    }

    k = 0;

    for (j = 0; j < cols; j++) {
      if (i == 0 && j == 0) {
        sprintf(&rows[i][k], "%*s", widths[j], "");
      } else if (i == 0) {
        value = a + j - 1;
        sprintf(&rows[i][k], "%*u", widths[j], value);
      } else if (j == 0) {
        value = c + i - 1;
        sprintf(&rows[i][k], "%*u", widths[j], value);
      } else {
        value = (c + i - 1) * (a + j - 1);
        sprintf(&rows[i][k], "%*u", widths[j], value);
      }

      k = k + widths[j];

      if (j + 1 < cols) {
        rows[i][k] = ' ';
        k++;
      }
    }

    rows[i][k] = '\0';
  }

  free(widths);

  return rows;
}
