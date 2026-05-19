#include "viikko.h"

#include <stdio.h>
#include <time.h>

/*
This function takes a date as input and prints the day of the week for that
date. The date is given as three integers: the day, the month, and the year. The
function prints the name of the day of the week (e.g. "Monday", "Tuesday", etc.)
for the given date. It uses the struct tm structure to represent the date and
the mktime function to convert it to a time_t value. The strftime function is
used to format the output string.
*/
void viikko(int day, int month, int year) {
  struct tm aika;
  char rivi[100];
  int i;

  aika.tm_sec = 0;
  aika.tm_min = 0;
  aika.tm_hour = 12;
  aika.tm_mday = day;
  aika.tm_mon = month - 1;
  aika.tm_year = year - 1900;
  aika.tm_isdst = -1;

  mktime(&aika);

  while (aika.tm_wday != 1) {
    aika.tm_mday--;
    mktime(&aika);
  }

  for (i = 0; i < 7; i++) {
    strftime(rivi, sizeof(rivi), "%A %d. %B %Y", &aika);
    printf("%s\n", rivi);

    aika.tm_mday++;
    mktime(&aika);
  }
}
