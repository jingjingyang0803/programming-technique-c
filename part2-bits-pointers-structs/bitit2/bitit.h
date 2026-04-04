/*
EXERCISE: Reversing bits

Write a program that defines functions to reverse the bit representation of
a variable of a certain type and output information about the reversed value and
bit representation.
*/
#ifndef BITIT_H
#define BITIT_H

#include <stdio.h>
#include <stdlib.h>

void kaannaScharBitit(signed char *x);
void kaannaShortBitit(short *x);
void kaannaIntBitit(int *x);
void kaannaLongBitit(long *x);

#endif /* BITIT_H */
