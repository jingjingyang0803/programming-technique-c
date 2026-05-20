/*
EXERCISE: Tidy spaces
Write a program that reads a text file and writes a new file where all sequences
of whitespace characters (spaces, tabs, newlines) are replaced by a single
space. The program should take the input and output file names as command-line
arguments. The program should also count the number of characters read and
written, and print these counts to the standard output.
*/

#ifndef YKKOSVALIT_H
#define YKKOSVALIT_H

typedef struct UintPari {
  unsigned int x;
  unsigned int y;
} UintPari;

UintPari ykkosValit(const char *inputFN, const char *outputFN);

#endif
