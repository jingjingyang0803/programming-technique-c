/*
EXERCISE: Parameter Table

Implement a program that prints all command line parameters with their indexes
in a "nicely formatted" table.
The values ​​of the first column are aligned to the right end of the column
and the values ​​of the second column are aligned to the left.

Example output:
###################
#  1 | China      #
#----+------------#
#  2 | India      #
#----+------------#
#  3 | USA        #
#----+------------#
#  4 | Indonesia  #
#----+------------#
#  5 | Brazil     #
#----+------------#
#  6 | Pakistan   #
#----+------------#
#  7 | Nigeria    #
#----+------------#
#  8 | Bangladesh #
#----+------------#
#  9 | Russia     #
#----+------------#
# 10 | Japan      #
###################
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int i;
  int total_params;
  int max_index_width;
  int max_param_width;

  /* Calculate the maximum width for index and parameter columns */
  total_params = argc - 1;
  max_index_width = 1;
  max_param_width = 1;
  for (i = 1; i < argc; i++) {
    while (total_params >= 10) {
      total_params /= 10;
      max_index_width++;
    }
    if (strlen(argv[i]) > max_param_width) {
      max_param_width = strlen(argv[i]);
    }
  }

  /* Print the top border of the table */
  for (i = 0; i < max_index_width + max_param_width + 7; i++) {
    printf("#");
  }
  printf("\n");

  /* Print each parameter with its index in a formatted way */
  for (i = 1; i < argc; i++) {
    printf("# %*d | %-*s #\n", max_index_width, i, max_param_width, argv[i]);

    /* Print the separator line after each parameter except the last one */
    if (i < argc - 1) {
      printf("#-");
      int j;
      for (j = 0; j < max_index_width; j++) {
        printf("-");
      }
      printf("-+-");
      for (j = 0; j < max_param_width; j++) {
        printf("-");
      }
      printf("-#\n");
    }
  }

  /* Print the bottom border of the table */
  for (i = 0; i < max_index_width + max_param_width + 7; i++) {
    printf("#");
  }
  printf("\n");

  return 0;
}