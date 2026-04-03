/*
EXERCISE: IEEE 754

Write a program that takes a 32-bit binary string as input and decodes it
according to the IEEE 754 single-precision floating-point format. The program
should output the following:
1. The value of the fraction (the significand) as a decimal number.
2. The value of the exponent as a decimal number (after subtracting the bias).
3. The sign of the number (either '+' or '-').
4. The overall value of the floating-point number as a decimal number.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  size_t len;
  size_t i;
  char *binary_str;

  /*Variables to hold the sign bit, exponent bits, and fraction bits as
   * strings, with null terminators */
  char sign_bit;
  char exponent_bits[9];
  char fraction_bits[24];

  double fraction_value;
  double value_part;
  int exponent_value;
  char sign;
  double overall_value;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <32-bit_binary_string>\n", argv[0]);
    return 1;
  }

  binary_str = argv[1];
  len = strlen(binary_str);

  if (len != 32) {
    fprintf(stderr,
            "Error: Input must be a 32-character long binary string, not %zu "
            "characters.\n",
            len);
    return 1;
  }

  for (i = 0; i < len; i++) {
    if (binary_str[i] != '0' && binary_str[i] != '1') {
      fprintf(stderr, "Error: Input must consist only of '0' and '1'.\n");
      return 1;
    }
  }

  sign_bit = binary_str[0];
  strncpy(exponent_bits, binary_str + 1, 8);
  exponent_bits[8] = '\0';
  strncpy(fraction_bits, binary_str + 9, 23);
  fraction_bits[23] = '\0';

  fraction_value = 0.0;
  for (i = 0; i < 23; i++) {
    if (fraction_bits[i] == '1') {
      fraction_value += 1.0 / (1 << (i + 1));
    }
  }
  value_part = 1.0 + fraction_value;

  exponent_value = 0;
  for (i = 0; i < 8; i++) {
    if (exponent_bits[i] == '1') {
      exponent_value += 1 << (7 - i);
    }
  }
  exponent_value -= 127;

  sign = (sign_bit == '0') ? '+' : '-';

  /* Calculate the overall value using ldexp,
   * which computes value_part * (2^exponent_value) */
  overall_value = (sign == '+') ? ldexp(value_part, exponent_value)
                                : -ldexp(value_part, exponent_value);

  printf("%.15f\n", value_part);
  printf("%d\n", exponent_value);
  printf("%c\n", sign);
  printf("%.15f\n", overall_value);

  return 0;
}
