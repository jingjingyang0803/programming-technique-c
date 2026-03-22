/*
EXERCISE: Two's complement
Implement a program that receives as argv[1] a string consisting of the digit
characters '0' and '1' and outputs the corresponding integer value when the
string is assumed to describe a two's complement representation of an integer.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  size_t len;
  size_t i;
  char *binary_str;
  int value;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <binary_string>\n", argv[0]);
    return 1;
  }

  binary_str = argv[1];
  len = strlen(binary_str);
  value = 0;

  /* Check if the string is valid (only '0' and '1') */
  for (i = 0; i < len; i++) {
    if (binary_str[i] != '0' && binary_str[i] != '1') {
      fprintf(stderr, "Invalid input: %s\n", binary_str);
      return 1;
    }
  }

  /* Convert the binary string to an integer value.
   *
   * First, interpret the bit string as an unsigned binary number.
   * This is done by constructing the value bit by bit:
   *   value = value * 2 + current_bit
   *
   * At this stage, even negative numbers (in two's complement form)
   * are treated as large positive values.
   */
  for (i = 0; i < len; i++) {
    value <<= 1;                    /* Shift left = multiply by 2 */
    value += (binary_str[i] - '0'); /* Add current bit (0 or 1) */
  }

  /* If the most significant bit is 1, the number is negative
   * in two's complement representation.
   *
   * In two's complement, a negative value is represented as:
   *   value = unsigned_value - 2^n
   * where n is the number of bits.
   *
   * Therefore, subtract 2^len to obtain the correct negative value.
   */
  if (binary_str[0] == '1') {
    value -= (1 << len);
  }

  printf("%d\n", value);
  return 0;
}