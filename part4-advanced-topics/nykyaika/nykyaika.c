#include <stdio.h>
#include <time.h>

int main(void) {
  time_t nyt;
  struct tm *aika;
  const char *paivat[] = {"Sunnuntai", "Maanantai", "Tiistai", "Keskiviikko",
                          "Torstai",   "Perjantai", "Lauantai"};

  nyt = time(NULL);
  aika = localtime(&nyt);

  if (aika == NULL) {
    return 1;
  }

  printf("%s %02d.%02d.%04d klo %02d:%02d\n", paivat[aika->tm_wday],
         aika->tm_mday, aika->tm_mon + 1, aika->tm_year + 1900, aika->tm_hour,
         aika->tm_min);

  return 0;
}
