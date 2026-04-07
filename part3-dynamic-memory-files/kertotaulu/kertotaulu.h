/*
EXERCISE: Multiplication table #3
*/

#ifndef KERTOTAULU_H
#define KERTOTAULU_H

#include <stdint.h> /* For uint. */

typedef uint32_t
    uint; /* Define uint as an alias for uint32_t for convenience. */

/***************** Structure definition for multiplication table
 * *****************/
typedef struct {
  uint a;            /* The starting value for the columns. */
  uint b;            /* The ending value for the columns. */
  uint c;            /* The starting value for the rows. */
  uint d;            /* The ending value for the rows. */
  uint **kertotaulu; /* A pointer to a 2D array (array of pointers) to hold the
                        multiplication table. */
} Kertotaulu;        /* Kertotaulu = Finnish for multiplication table. */

/***************** Function prototypes for multiplication table operations
 * *****************/
/* Function prototype for creating a multiplication table with specified
 * parameters. */
Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d);

/* Function prototype for destroying a multiplication table and freeing its
 * memory. */
void tuhoaKertotaulu(Kertotaulu *kt);

#endif /* KERTOTAULU_H */
