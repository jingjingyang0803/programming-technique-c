/*
EXERCISE: Reading a line of input

Write a function that reads a line of input from the user and returns it as a
dynamically allocated string. The function should take a file stream and a
delimiter character as arguments, and read characters from the stream until the
delimiter is encountered. The function should also take a pointer to a size_t
variable as an argument, and store the length of the string in that variable.
The function should return a pointer to the dynamically allocated string, or
NULL if an error occurs.
*/

#ifndef LUKU_H
#define LUKU_H

#include <stddef.h>
#include <stdio.h>

char *lueKunnes(FILE *instream, char delim, size_t *n);

#endif
