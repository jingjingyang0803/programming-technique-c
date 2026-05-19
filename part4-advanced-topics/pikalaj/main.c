/*
 * This program implements quicksort using recursive 3-way partitioning.
 * The public function pikalajittele(start, end, t) sorts the integer array t
 * from index start to index end.
 *
 * Compile-time options:
 * - If KOLMIJAON_RAJAT is defined, the program prints the start and end
 *   indices of every subinterval processed by kolmijako:
 *       Kolmijako start end
 *
 * - If KOLMIJAON_TYO is defined, the program prints the total length of all
 *   subintervals processed by kolmijako after sorting is complete:
 *       Kolmijaon kokonaistyö: len
 *
 * - If both macros are defined, both kinds of information are printed.
 */

#include "pikalaj.h"
#include <stdio.h>

int main(void) {
  int taulu[18] = {97, 44, 7,  57, 7,  51, 82, 65, 85,
                   82, 13, 98, 46, 38, 3,  15, 13, 29};
  pikalajittele(0, 17, taulu);
  return 0;
}
