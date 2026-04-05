/*
EXERCISE: Days of the month

Practice the use of enum constants, string literals and two-dimensional arrays.

*/

#ifndef KUUKAUDET_H
#define KUUKAUDET_H

#include <stdio.h>
#include <stdlib.h>

/* Enum for months */
enum kuukausi {
  TAMMIKUU = 0,
  HELMIKUU,
  MAALISKUU,
  HUHTIKUU,
  TOUKOKUU,
  KESAKUU,
  HEINAKUU,
  ELOKUU,
  SYYSKUU,
  LOKAKUU,
  MARRASKUU,
  JOULUKUU
};

/* Enum for number of months */
enum KK_LKM { KK_LKM = 12 };

/* Array of month names using all lowercase letters */
extern const char *KK_NIMET[KK_LKM];

/* Array of number of days (0 = normal year, 1 = leap year) */
extern const char KK_PAIVAT[2][KK_LKM];

/* Returns 1 if the given year is a leap year, otherwise returns 0 */
int karkausvuosi(int vuosi);

/* Returns the number of days in the given month and year */
char kkPituus(const char *monthName, int y);

#endif /* KUUKAUDET_H */
