#include "pvm.h"
#include <stdio.h>
#include <string.h>

/* Number of days in each month for normal and leap years. */
static const int PV_KK[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* Finnish weekday abbreviations, starting from Sunday. */
static const char *VK_PV[7] = {"su", "ma", "ti", "ke", "to", "pe", "la"};

/* Check whether a year is a leap year. */
static int isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Move the weekday forward by one day. */
static void nextWeekday(Pvm *pvm) {
  int i;
  for (i = 0; i < 7; i++) {
    if (strcmp(pvm->vk_pv, VK_PV[i]) == 0) {
      strcpy(pvm->vk_pv, VK_PV[(i + 1) % 7]);
      return;
    }
  }
}

/* Compare two dates without considering the weekday. */
static int compareDates(const Pvm *a, const Pvm *b) {
  if (a->vuosi != b->vuosi) {
    return a->vuosi < b->vuosi ? -1 : 1;
  }

  if (a->kk != b->kk) {
    return a->kk < b->kk ? -1 : 1;
  }

  if (a->pv != b->pv) {
    return a->pv < b->pv ? -1 : 1;
  }

  return 0;
}

/* Increment the date by one day. */
Pvm *kasvataPvm(Pvm *pvm) {
  int leap = isLeapYear(pvm->vuosi);

  pvm->pv++;

  /* Move to the next month if the current month has ended. */
  if (pvm->pv > PV_KK[leap][pvm->kk]) {
    pvm->pv = 1;
    pvm->kk++;

    /* Move to the next year after December. */
    if (pvm->kk > 12) {
      pvm->kk = 1;
      pvm->vuosi++;
    }
  }

  nextWeekday(pvm);

  return pvm;
}

/* Calculate the number of days between two dates. */
unsigned int pvmEro(const Pvm *a, const Pvm *b) {
  Pvm current;
  const Pvm *later;
  unsigned int days = 0;

  /* Start from the earlier date without modifying the originals. */
  if (compareDates(a, b) <= 0) {
    current = *a;
    later = b;
  } else {
    current = *b;
    later = a;
  }

  /* Count the days until the later date is reached. */
  while (compareDates(&current, later) < 0) {
    kasvataPvm(&current);
    days++;
  }

  return days;
}

/* Print the date in the required Finnish format. */
void tulostaPvm(Pvm *pvm) {
  printf("%s %d.%d.%d", pvm->vk_pv, pvm->pv, pvm->kk, pvm->vuosi);
}