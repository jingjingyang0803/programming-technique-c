/*
EXERCISE: 3D points
*/
#ifndef VAIHTO_H
#define VAIHTO_H

typedef struct {
  double x;
  double y;
  double z;
} Piste3D;

/* Prints the coordinates of the point with the given precision.
    Note that this function does not print a new line!
*/
void tulosta(Piste3D p, int prec);

/* Returns the distance between the two points. */
double etaisyys(Piste3D p1, Piste3D p2);

#endif /* VAIHTO_H */
