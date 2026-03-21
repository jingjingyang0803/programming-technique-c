/*
Exercise: Multiplication table with command line parameters
Implement a program that receives four positive integers a , b, c and d as a
command line parameters and prints a multiplication table, which describes the
results of multiplications between  the numbers a..b and c..d in the form of a
multiplication table. The program can assume that a <= b and c <= d. The
multiplication table is formatted in such a way that numbers a...b are in its
top row and numbers c...d in its leftmost column.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b, c, d;
  int i, j;
  int max, width;

  if (argc != 5) {
    printf("Usage: %s a b c d\n", argv[0]);
    return 1;
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);
  d = atoi(argv[4]);

  /* Calculate the largest number in the table and its width */
  max = b * d;
  width = 1;
  while (max >= 10) {
    max /= 10;
    width++;
  }

  /* Print the top row of the table */
  for (i = 1; i <= width; i++) {
    printf(" ");
  }
  for (i = a; i <= b; i++) {
    printf(" %*d", width, i);
  }
  printf("\n");

  /* Print the multiplication table */
  for (i = c; i <= d; i++) {
    printf("%*d", width, i);
    for (j = a; j <= b; j++) {
      printf(" %*d", width, i * j);
    }
    printf("\n");
  }

  return 0;
}
