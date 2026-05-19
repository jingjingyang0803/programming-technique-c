/*
This program demonstrates how to determine the day of the week for a given date
in C. It uses the struct tm structure to represent the date and the mktime
function to convert it to a time_t value. The strftime function is used to
format the output string.
The program takes three command-line arguments: the day, the month, and the
year. It then calls the viikko function to print the day of the week for the
given date. The program also sets the locale to Finnish with UTF-8 encoding, so
that the output is in Finnish.
*/

#include <locale.h> /* Needed for using setlocale. */
#include <stdlib.h>

#include "viikko.h"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    return 1;
  }
  viikko(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  setlocale(LC_TIME,
            "fi_FI.utf8"); /* Switch to a Finnish locale with UTF-8 encoding. */
  viikko(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  return 0;
}
