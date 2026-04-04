/*
Store c into an unsigned int variable.
Calculate the minimum number of bits required to represent c. E.g. use this
simple procedure: Step through the bit representation of c in a right-to-left
order and find the position of the the last 1-bit. Representing c requires as
many bits as you traversed to find the last 1-bit (= leading zeros in front of
the last 1-bit can be left out). Must also handle the special case where c = 0
and there are no 1-bits. In this case c requires 1 bit. Let k denote the minimum
number of bits required (computed in step 2). Now select the shortest UTF-8 code
length that has at least k value bits. 1-byte code has 7 value bits, 2-byte code
has 11, 3-byte code has 16 and 4-byte code has 21 value bits. Encode the
rightmost k bits of c into the value bits of a UTF-8 code with the selected
length. Start with completely zeroed values. E.g in case of a 2-byte code
initialize utf8[0] = utf8[1] = 0 and also remember to set the end character
utf8[2] = '\0'. Write the value bits. We give here an example of storing the
code 228 of the character 'ä'. The bit representation of 228 is 11100100 and
requires at least 8 bits (there are no leading zeros): the shortest sufficient
option is a 2-byte UTF-8 code. First write the byte headers (the fixed bit
values on the left end): utf8[0] will have 1-bits at indices 7 and 6 and utf8[1]
a 1-bit at index 7. Here one useful operation could e.g. be utf8[1] = utf8[1] |
(1 << 7). Then write the rightmost 8 bits of the value c = 228  to the value
parts of the bytes  utf8[1] and utf8[0]. This means writing 1-bits to the but
indices 2 and 5 of utf8[1] and to bit indices 0 and 1 of utf8[0]. The bytes will
then have bit representations utf8[0] = 11000011 and utf8[1] = 10100100. Note
that only 1-bits are written explicitly: you do not need to explicitly write any
sinle 0-bits as the bytes were initially zeroed. The UTF-8 encoding is complete
and the function call can return.
 */

#include "utf8.h"

void utf8_koodaa(unsigned int c, unsigned char utf8[]) {
  int num_bits = 0;
  unsigned int temp = c;

  /* Calculate the number of bits required to represent c */
  if (c == 0) {
    num_bits = 1; /* Special case for c = 0 */
  } else {
    while (temp > 0) {
      num_bits++;
      temp >>= 1; /* Shift right to check the next bit */
    }
  }

  /* Determine the UTF-8 code length based on the number of bits */
  if (num_bits <= 7) {
    utf8[0] = c & 0x7F; /* Store the value in the last 7 bits */
    utf8[1] = '\0';     /* Null-terminate the string */
  } else if (num_bits <= 11) {
    utf8[0] = (c >> 6) | 0xC0;   /* Set the first byte header (110xxxxx) */
    utf8[1] = (c & 0x3F) | 0x80; /* Set the second byte header (10xxxxxx) */
    utf8[2] = '\0';              /* Null-terminate the string */
  } else if (num_bits <= 16) {
    utf8[0] = (c >> 12) | 0xE0; /* Set the first byte header (1110xxxx) */
    utf8[1] =
        ((c >> 6) & 0x3F) | 0x80; /* Set the second byte header (10xxxxxx) */
    utf8[2] = (c & 0x3F) | 0x80;  /* Set the third byte header (10xxxxxx) */
    utf8[3] = '\0';               /* Null-terminate the string */
  } else if (num_bits <= 21) {
    utf8[0] = (c >> 18) | 0xF0; /* Set the first byte header (11110xxx) */
    utf8[1] =
        ((c >> 12) & 0x3F) | 0x80; /* Set the second byte header (10xxxxxx) */
    utf8[2] =
        ((c >> 6) & 0x3F) | 0x80; /* Set the third byte header (10xxxxxx) */
    utf8[3] = (c & 0x3F) | 0x80;  /* Set the fourth byte header (10xxxxxx) */
    utf8[4] = '\0';               /* Null-terminate the string */
  }
}
