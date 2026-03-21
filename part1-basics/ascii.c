/*
EXERCISE: ASCII values
Implement a program that receives as command line parameters two integers a and
b , for which  a <= b , and prints the integers ​​a ... b and the characters
they represent. Your program may assume that the integers a and b are legal
values ​​for the char variable type (ie. they are not too large).
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s a b\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  if (a > b) {
    printf("Error: a must be less than or equal to b.\n");
    return 1;
  }

  int i;
  for (i = a; i <= b; i++) {
    /* Print the integer and its corresponding character */
    printf("%d: %c\n", i, (char)i);
  }

  return 0;
}