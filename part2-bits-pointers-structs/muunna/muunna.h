/*
EXERCISE: Array value transformation
*/

#ifndef MUUNNA_H
#define MUUNNA_H

/* Function pointer type for a function that takes a double and returns a double
 */
typedef double (*TransformFunc)(double);

/* Applies the given transformation function to each element of the array */
void muunnaTaulu(unsigned int size, double *array, TransformFunc trans);

#endif /* MUUNNA_H */
