/*
EXERCISE: String Concatenation
Write a function that takes a variable number of string arguments and
concatenates them into a single string. The function should allocate memory for
the resulting string and return a pointer to it. The last argument passed to the
function should be NULL, which indicates the end of the arguments. The function
should handle any number of string arguments and should not modify the input
strings. Remember to free the allocated memory after using the concatenated
string to avoid memory leaks.
*/

#ifndef YHDISTA_H
#define YHDISTA_H

char *yhdista(const char *mj, ...);

#endif
