/*
EXERCISE: Custom fprintf
Write a function that takes a variable number of arguments and prints them to a
specified output stream. The function should take a format string as its first
argument, which specifies how the subsequent arguments should be formatted. The
function should use the format string to determine how to print each argument.
The function should return the total number of characters printed.
*/

#ifndef TULOSTA_H
#define TULOSTA_H

#include <stddef.h>
#include <stdio.h>

size_t tulosta(FILE *td, const char *mj, ...);

#endif
