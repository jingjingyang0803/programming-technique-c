/* This program prints the current date and time in Finnish in the format:
 * viikonpäivä kk.pv.vvvv klo hh:mm */
#include <stdio.h>
#include <time.h>
/*
  struct tm is a structure used to hold the time and date. Its members are as
  follows:

  int tm_sec;   seconds after the minute (0 to 59)
  int tm_min;   minutes after the hour (0 to 59)
  int tm_hour;  hours since midnight (0 to 23)
  int tm_mday;  day of the month (1 to 31)
  int tm_mon;   months since January (0 to 11)
  int tm_year;  years since 1900
  int tm_wday;  days since Sunday (0 to 6 Sunday=0)
*/

int main(void) {
  time_t nyt;
  struct tm *aika;
  const char *paivat[] = {"Sunnuntai", "Maanantai", "Tiistai", "Keskiviikko",
                          "Torstai",   "Perjantai", "Lauantai"};

  nyt = time(NULL);
  aika = localtime(&nyt);

  /* Check if localtime returned NULL, which indicates an error */
  if (aika == NULL) {
    return 1;
  }

  printf("%s %02d.%02d.%04d klo %02d:%02d\n", paivat[aika->tm_wday],
         aika->tm_mday, aika->tm_mon + 1, aika->tm_year + 1900, aika->tm_hour,
         aika->tm_min);

  return 0;
}
