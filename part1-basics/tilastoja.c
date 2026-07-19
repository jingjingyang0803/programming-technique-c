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
    int count[MAX_N] = {0};
    int n = argc - 1;
    int i, j;
    int max_count = 1;
    double min, max;

    if (n <= 0 || n > MAX_N) {
        printf("Usage: %s number1 number2 ...\n", argv[0]);
        return 1;
    }

    numbers[0] = atof(argv[1]);
    min = max = numbers[0];
  
    /* Convert arguments and find min/max */
    for (i = 0; i < n; i++) {
        numbers[i] = atof(argv[i + 1]);

        if (i == 0) {
            min = max = numbers[i];
        } else {
            if (numbers[i] < min)
                min = numbers[i];

            if (numbers[i] > max)
                max = numbers[i];
        }
    }

    printf("Pienin: %f\n", min);
    printf("Suurin: %f\n", max);

    /* Count occurrences */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (numbers[i] == numbers[j])
                count[i]++;
        }

        if (count[i] > max_count)
            max_count = count[i];
    }

    /* Print unique numbers */
    for (i = 0; i < n; i++) {
        if (count[i] == 1)
            break;
    }

    if (i < n) {
        printf("Ainutlaatuiset:");

        for (i = 0; i < n; i++) {
            if (count[i] == 1)
                printf(" %f", numbers[i]);
        }

        printf("\n");
    }

    /* Print most frequent numbers */
    if (max_count > 1) {
        printf("Useimmiten esiintyneet (%d kertaa):", max_count);

        for (i = 0; i < n; i++) {
            if (count[i] != max_count)
                continue;

            /* Skip values already handled */
            for (j = 0; j < i; j++) {
                if (numbers[i] == numbers[j])
                    break;
            }

            if (j == i)
                printf(" %f", numbers[i]);
        }

        printf("\n");
    }

    return 0;
}
