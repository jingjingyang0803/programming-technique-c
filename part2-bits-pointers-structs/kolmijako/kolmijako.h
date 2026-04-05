/*
EXERCISE: 3-way partitioning

Partitions the array arr of length n into three parts based on two pivot values
pivot1 and pivot2:
- The first part contains all elements less than pivot1.
- The second part contains all elements greater than or equal to pivot1 and less
than pivot2.
- The third part contains all elements greater than or equal to pivot2.
*/
#ifndef KOLMIJAKO_H
#define KOLMIJAKO_H

/* A struct to hold the return values of kolmijako. */
typedef struct {
  int x; /* The index of the first element in the middle part. */
  int y; /* The index of the first element in the last part. */
} IntPari;

/* Partitions the array t of length n into three parts based on the values at
 * pivot1 and pivot2. The function returns an IntPari struct where:
 * - x is the index of the first element in the middle part (greater than or
   equal to pivot1).
 * - y is the index of the first element in the last part (greater than or equal
   to pivot2).
 * The function also updates the values pointed to by p1 and p2 with x and y,
 * respectively, if they are not null pointers.
 */
IntPari kolmijako(unsigned int n, int t[], int pivot1, int pivot2, int *p1,
                  int *p2);

#endif /* KOLMIJAKO_H */
