/*

EXERCISE: UTF-8 encoding

Write a function that takes an unsigned int variable c and an array of unsigned
char variables utf8 of length 5 as parameters. The function should encode the
value of c into a UTF-8 code and store the code into the array utf8.
 */

#ifndef UTF8_H
#define UTF8_H
#include <stdio.h>
#include <stdlib.h>

void utf8_koodaa(unsigned int c, unsigned char utf8[]);

#endif /* UTF8_H */
