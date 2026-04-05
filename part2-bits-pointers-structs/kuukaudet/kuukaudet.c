#include "kuukaudet.h"
#include <string.h>

const char *KK_NIMET[KK_LKM] = {
    "tammikuu", "helmikuu", "maaliskuu", "huhtikuu", "toukokuu",  "kesäkuu",
    "heinäkuu", "elokuu",   "syyskuu",   "lokakuu",  "marraskuu", "joulukuu"};

const char KK_PAIVAT[2][KK_LKM] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, /* Regular year */
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  /* Leap year */
};

int karkausvuosi(int vuosi) {
  if ((vuosi % 4 == 0 && vuosi % 100 != 0) || (vuosi % 400 == 0)) {
    return 1; /* Leap year */
  }
  return 0; /* Not a leap year */
}

char kkPituus(const char *monthName, int y) {
  int i;
  for (i = 0; i < 12; ++i) {
    /* Use strcasecmp for case-insensitive comparison */
    if (strcasecmp(monthName, KK_NIMET[i]) == 0) {
      return KK_PAIVAT[karkausvuosi(y)][i];
    }
  }
  return -1; /* Month not found */
}
