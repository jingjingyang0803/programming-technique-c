/*
This program demonstrates how to read lines of input from the user until an
empty line is entered. It uses a function called `lueKunnes` to read input until
a specified delimiter (in this case, a newline character) is encountered. The
program also handles dynamic memory allocation for the input lines and prints
the length of each line read, as well as the total length of the line using
`strlen`. The program continues to read lines until an empty line is entered or
the end of input is reached.
*/

#include "luku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *line = NULL;
  size_t len = 0;
  do {
    line = lueKunnes(
        stdin, '\n',
        &len);     /* Reads until the character '\n', that is, one input line.*/
    if (len > 0) { /* The below lines are Finnish for "I read an %lu-character
                      line: %s" and "strlen(line): %lu". */
      printf("Luin %lu-merkkisen rivin: %s\n", (unsigned long)len, line);
      printf("strlen(rivi): %lu\n", (unsigned long)strlen(line));
      free(line);
    } else if (line != NULL) { /* The below line is Finnish for "You gave an
                                  empty line, now quitting...\n". */
      printf("Annoit tyhjän rivin, nyt lopetetaan...\n");
      free(line);
      break;
    } else { /* The below line is Finnish for "Quitting because no input line
                could be read!\n". */
      printf("Syöteriviä ei saatu luettua, joten lopetetaan!\n");
    }
  } while (line != NULL); /* Did the input end? lueKunnes returns NULL if
                             nothing was read. */
  return 0;
}
