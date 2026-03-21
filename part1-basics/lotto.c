/* EXERCISE: Lottery numbers checker
Implement a program that receives the winning lottery numbers and the numbers of
a single lottery ticket as command line parameters and prints information about
how many correct numbers the lottery ticket contains. Both the winning numbers
and the lottery ticket consist of seven integers, for which no lower or upper
limits are defined in this task: each number can in principle be an arbitrary
int value. Each number is given to the program as a separate command line
parameter. Thus the program receives a total of 14 actual command line
parameters: the first 7 describe the winning numbers and the next 7 the lottery
ticket. The numbers are not otherwise given in any particular order (e.g.
neither the winning numbers nor the lottery ticket numbers are necessarily in
ascending order).
*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_COUNT 7

int main(int argc, char *argv[]) {
  int i, j, count;
  int winning[NUM_COUNT], ticket[NUM_COUNT];
  int correct[NUM_COUNT];

  count = 0;

  if (argc != NUM_COUNT * 2 + 1) {
    printf("Usage: %s win1 win2 win3 win4 win5 win6 win7 "
           "ticket1 ticket2 ticket3 ticket4 ticket5 ticket6 ticket7\n",
           argv[0]);
    return 1;
  }

  /* Parse the winning numbers and the lottery ticket numbers */
  for (i = 0; i < NUM_COUNT; i++) {
    winning[i] = atoi(argv[i + 1]);
    ticket[i] = atoi(argv[i + NUM_COUNT + 1]);
  }

  /* Print the winning numbers */
  printf("Voittorivi:");
  for (i = 0; i < NUM_COUNT; i++) {
    printf(" %d", winning[i]);
  }

  /* Print the lottery ticket numbers */
  printf("\nLottorivi:");
  for (i = 0; i < NUM_COUNT; i++) {
    printf(" %d", ticket[i]);
  }
  printf("\n");

  /* Store and count the correct numbers */
  for (i = 0; i < NUM_COUNT; i++) {
    for (j = 0; j < NUM_COUNT; j++) {
      if (ticket[i] == winning[j]) {
        correct[count] = ticket[i];
        count++;
        break;
      }
    }
  }

  /* Print the results */
  if (count == 0) {
    printf("Ei yhtään oikein!");
  } else {
    printf("%d oikein:", count);
    for (i = 0; i < count; i++) {
      printf(" %d", correct[i]);
    }
  }
  printf("\n");

  return 0;
}
