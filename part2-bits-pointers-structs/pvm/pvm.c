#include "pvm.h"
#include <stdio.h>
#include <string.h>

/* Days in each month, with a placeholder for the 0th month. */
const unsigned int PV_KK[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, /* Non-leap year */
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  /* Leap year */
};

/* Weekday abbreviations in Finnish. */
const char *VK_PV[7] = {"su", "ma", "ti", "ke", "to", "pe", "la"};

/* Helper function: Determines if a given year is a leap year. */
int isLeapYear(unsigned int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Helper function: Calculates the weekday for a given date using Zeller's
 * Congruence. */
void laske_viikonpaiva(Pvm *p) {
  unsigned int d, m, y, K, J, h, vk_index;

  d = p->pv;
  m = p->kk;
  y = p->vuosi;

  /* Zeller's Congruence:
   * h = (d + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7
   * where d = day of the month
   *       m = month (3=March, 4=April, ..., 12=December, 13=January,
   *                  14=February)
   *       K = year % 100 (the last two digits of the year)
   *       J = year / 100 (the first two digits of the year)
   */
  if (m <= 2) {
    m += 12;
    y -= 1;
  }

  K = y % 100;
  J = y / 100;

  h = (d + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

  /* Zeller: 0=Sunday */
  vk_index =
      h %
      7; /* Map Zeller's output to our weekday index (0=su, 1=ma, ..., 6=la) */

  strcpy(p->vk_pv, VK_PV[vk_index]);
}

Pvm *kasvataPvm(Pvm *p) {
  int leap; /* Whether the current year is a leap year. */

  /* Increment the day. */
  p->pv += 1;
  /* Check if the day exceeds the number of days in the month. */
  leap = isLeapYear(p->vuosi);
  if (p->pv > PV_KK[leap][p->kk]) { /* If the day exceeds the number of days in
        the month */
    p->pv = 1;                      /* Reset day to 1. */
    p->kk += 1;                     /* Increment month. */
    if (p->kk > 12) {               /* If the month exceeds 12 */
      p->kk = 1;                    /* Reset month to 1. */
      p->vuosi += 1;                /* Increment year. */
    }
  }
  /* Update the weekday. */
  laske_viikonpaiva(p);

  return p; /* Return the pointer to the incremented date. */
}

/* Calculate the total number of days from a reference date (e.g., 1.1.1900)
 * to each date and return the absolute difference. */
unsigned int pvmEro(const Pvm *a, const Pvm *b) {
  unsigned int days_a, days_b;
  unsigned int year;

  /* Step 1: Initialize the day counters with the day of the month. */
  days_a = a->pv;
  days_b = b->pv;

  /* Step 2: Add the days in the preceding months for each date. */
  for (year = 1; year < a->kk; ++year) {
    days_a += PV_KK[isLeapYear(a->vuosi)][year];
  }
  for (year = 1; year < b->kk; ++year) {
    days_b += PV_KK[isLeapYear(b->vuosi)][year];
  }

  /* Step 3: Add the days for each year from the reference year to the given
   * year. */
  for (year = 1900; year < a->vuosi; ++year) {
    if (isLeapYear(year)) {
      days_a += 366;
    } else {
      days_a += 365;
    }
  }
  for (year = 1900; year < b->vuosi; ++year) {
    if (isLeapYear(year)) {
      days_b += 366;
    } else {
      days_b += 365;
    }
  }

  /* Step 4: Return the absolute difference in days. */
  return (days_a > days_b) ? (days_a - days_b) : (days_b - days_a);
}

void tulostaPvm(Pvm *pvm) {
  printf("%s %u.%u.%u", pvm->vk_pv, pvm->pv, pvm->kk, pvm->vuosi);
}
