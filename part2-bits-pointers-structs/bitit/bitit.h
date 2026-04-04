/*
EXERCISE: Reading bits

Write a program that defines functions to inspect a variable of a certain type
and output information about its value and bit representation.
*/
#ifndef BITIT_H
#define BITIT_H

#include <stdio.h>
#include <stdlib.h>

/*
Outputs on separate lines the following four pieces of information about the
received parameter signed char x:
The value of x .
The bit representation of x.
The number of 0 bits in the bit representation of x .
The number of 1 bits in the bit representation of x .
About inspecting the bit representation: process the bits of x in the order of
printing, that is, "from left to right". Parameter x is of a char type, so its
bit representation consists of CHAR_BIT bits. The order "from left to right
means" that the bits should be processed in the "bit index" order
CHAR_BIT-1...0, i.e. actually from the end to the beginning. For each bit (and
using index variable i): examine the bit value e.g. by doing (x >> i) & 1 and
output the result (which is either 0 or 1). This is also a good opportunity to
update information about 1 and 0 bit counts.
*/
void scharBitit(signed char x);

/*
Works otherwise like scharBitit, but now the parameter type is short int .
More or less the only difference is the number of bits to process: now you have
to inspect a short int variable that contains sizeof(short int) x CHAR_BIT bits.
 */
void shortBitit(short int x);

/*
Like above, but the parameter type is int (and thus there will be sizeof(int) x
CHAR_BIT bits to process).
 */
void intBitit(int x);

/*
Like above, but the parameter type is long int.
 */
void longBitit(long int x);

#endif /* BITIT_H */
