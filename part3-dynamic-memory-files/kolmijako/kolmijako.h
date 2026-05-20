/*
EXERCISE: 3-way partitioning #2
Write a function kolmijako_gen that takes an array of n elements of size size
and two pivot indices pivot1 and pivot2. The function should rearrange the
elements in the array so that all elements less than the element at pivot1 come
first, followed by all elements between the elements at pivot1 and pivot2,
followed by all elements greater than the element at pivot2. The function should
also return the new indices of the pivots after partitioning.
 */

#ifndef KOLMIJAKO_H
#define KOLMIJAKO_H

#include <stddef.h>

void kolmijako_gen(void *t, size_t n, size_t size, size_t pivot1, size_t pivot2,
                   int (*cmp)(const void *, const void *), size_t *p1,
                   size_t *p2);

#endif
