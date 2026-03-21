/*
Exercise: Statistics with command line parameters

Implement a program that receives a set of numbers (which should be treated as
double values) as command line parameters ​​and prints the following basic
statistics about them:

What was the smallest number?

What was the largest number?

Unique numbers: which numbers appeared only once?
 If no number was unique, this line is left completely unprinted!

which number (or numbers) occurred most often
 If all numbers are unique, this line is left completely unprinted!
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int main(int argc, char *argv[]) {
  double numbers[MAX_N];
  int count[MAX_N];
  double min, max;
  int i, j;
  int has_unique, max_count;

  if (argc < 2) {
    printf("Usage: %s number1 number2 ...\n", argv[0]);
    return 1;
  }

  /* Convert command line arguments to double and initialize count array */
  for (i = 1; i < argc; i++) {
    numbers[i - 1] = atof(argv[i]);
    count[i - 1] = 0;
  }

  /* Find min and max */
  min = max = numbers[0];
  for (i = 1; i < argc - 1; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }

  /* Count occurrences of each number */
  for (i = 0; i < argc - 1; i++) {
    for (j = 0; j < argc - 1; j++) {
      if (numbers[i] == numbers[j]) {
        count[i]++;
      }
    }
  }

  /* Check if there are any unique numbers and find the maximum count */
  has_unique = 0;
  max_count = 1;
  for (i = 0; i < argc - 1; i++) {
    if (count[i] == 1) {
      has_unique = 1;
    }
    if (count[i] > max_count) {
      max_count = count[i];
    }
  }

  /* Print min and max */
  printf("Pienin: %f\n", min);
  printf("Suurin: %f\n", max);

  /* Print unique numbers if there are any */
  if (has_unique > 0) {
    printf("Ainutlaatuiset:");

    for (i = 0; i < argc - 1; i++) {
      if (count[i] == 1) {
        printf(" %f", numbers[i]);
      }
    }
    printf("\n");
  }

  /* Print most frequently occurring numbers if there are any */
  if (max_count > 1) {
    printf("Useimmiten esiintyneet (%d kertaa):", max_count);

    for (i = 0; i < argc - 1; i++) {
      if (count[i] == max_count) {

        /* check if already printed */
        int seen_before = 0;

        for (j = 0; j < i; j++) {
          if (numbers[j] == numbers[i]) {
            seen_before = 1;
            break;
          }
        }

        if (!seen_before) {
          printf(" %f", numbers[i]);
        }
      }
    }
    printf("\n");
  }

  return 0;
}