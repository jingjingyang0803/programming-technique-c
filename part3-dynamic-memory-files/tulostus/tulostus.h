/*
EXERCISE: Printing to a file
Write a function that takes an array of doubles, its size, a name for the array,
a precision for printing the numbers, and a filename. The function should print
the contents of the array to the given file in a nicely formatted way. Each
number should be printed with the specified precision, and the output should
include the name of the array.
*/

#ifndef TULOSTUS_H
#define TULOSTUS_H

#include <stddef.h>

void tulostaDblTaulu(double *arr, size_t count, const char *arrName, int prec,
                     const char *filename);

#endif
