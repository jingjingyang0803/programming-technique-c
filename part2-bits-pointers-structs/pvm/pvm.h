/*
EXERCISE: Dates
*/
#ifndef PVM_H
#define PVM_H

/* Defines a date with day, month and year. */
typedef struct {
  unsigned int pv;    /* day */
  unsigned int kk;    /* month */
  unsigned int vuosi; /* year */
  char vk_pv[3];      /* weekday abbreviation (e.g., "ma" for Monday) */
} Pvm;

/* Increments a date by one day, taking into account the varying number of
 * days in each month and leap years.
 * The function may assume that pvm represents a legal date. */
Pvm *kasvataPvm(Pvm *p);

/* Calculates the difference in days between two dates. */
unsigned int pvmEro(const Pvm *a, const Pvm *b);

/* Prints a date in the format "weekday day.month.year".
 * E.g. the ouput corresponding to Friday 1.4.2016 would be "pe 1.4.2016".*/
void tulostaPvm(Pvm *pvm);

#endif /* PVM_H */
