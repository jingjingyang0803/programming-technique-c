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

/* Partitions a segment of an array consisting of n elements, starting from
 * address t into three parts using the values originally stored at indices
 * pivot1 and pivot2 as pivots.
 *
 * First, if t[pivot1] > t[pivot2], the pivot index values are swapped so that
 * t[pivot1] <= t[pivot2].
 *
 * After the partitioning:
 * - all values smaller than the first pivot are before index less1,
 * - the first pivot is at index less1,
 * - all remaining values smaller than the second pivot are between
 *   indices less1 + 1 and less2 - 1,
 * - the second pivot is at index less2,
 * - all remaining values are at indices greater than less2.
 *
 * The function returns the pivot final positions redundantly in two ways:
 * - through the returned IntPari value, where x = less1 and y = less2,
 * - through the pointer parameters p1 and p2, if they are not null pointers.
 *
 * Parameters:
 * - n: length of the array t
 * - t: array to be partitioned
 * - pivot1: index of the first pivot in t
 * - pivot2: index of the second pivot in t
 * - p1: output pointer for less1, or 0 if not needed
 * - p2: output pointer for less2, or 0 if not needed
 */
IntPari kolmijako(unsigned int n, int t[], int pivot1, int pivot2, int *p1,
                  int *p2);

#endif /* KOLMIJAKO_H */
