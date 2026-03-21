/*
EXERCISE: Quadratic equation solver
Implement a program that receives as command line parameters three numbers a , b
and c , which are interpreted to describe a quadratic equation of form ax 2 + bx
+ c = 0 .
The program should print the solution of the equation on the screen with three
decimal places .
If the equation has two solutions, the smaller one is printed first, and one
space is printed between the solutions.
If the equation has no real solution,the message "Ei ratkaisua" is printed.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s a b c\n", argv[0]);
    return 1;
  }

  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);

  double discriminant = b * b - 4 * a * c;

  if (discriminant < 0) {
    printf("Ei ratkaisua\n");
  } else if (discriminant == 0) {
    double solution = -b / (2 * a);
    printf("%.3f\n", solution);
  } else {
    double sqrt_discriminant = sqrt(discriminant);
    double solution1 = (-b - sqrt_discriminant) / (2 * a);
    double solution2 = (-b + sqrt_discriminant) / (2 * a);
    if (solution1 < solution2) {
      printf("%.3f %.3f\n", solution1, solution2);
    } else {
      printf("%.3f %.3f\n", solution2, solution1);
    }
  }

  return 0;
}
