/*
EXERCISE: Multiplication table
Implement a program that prints the multiplication table for the number interval
1, ..., 15. The top row of the multiplication table is a header row listing the
numbers ​​1, ..., 15 and in similar manner the leftmost column is a header
column listing the numbers ​​1, ..., 15. The sign 'x', denoting the
multiplication operation, is printed in the upper left corner (= the
intersection of the header row and header column). The other cell values express
the results of multiplying the numbers in the corresponding header column and
header rows. Each value of the multiplication table is printed 4 characters wide
(this refers to the width parameter given to the printf function). As the
largest value in the table has three digits, the effect is that the columns will
be aligned vertically and be separated from each other by at least one space.
*/
#include <stdio.h>

int main(void) {
  const int MIN = 1;
  const int MAX = 15;

  /* Print the header row */
  int i, j;
  printf("   x");
  for (i = MIN; i <= MAX; i++) {
    printf("%4d", i);
  }
  printf("\n");

  /* Print the multiplication table */
  for (i = MIN; i <= MAX; i++) {
    /* Print the header column */
    printf("%4d", i);
    /* Print the multiplication results for the current row */
    for (j = MIN; j <= MAX; j++) {
      printf("%4d", i * j);
    }
    printf("\n");
  }

  return 0;
}