/*
EXERCISE: Fractions
*/
#ifndef MURTOLUKU_H
#define MURTOLUKU_H

/* Defines a fraction with a numerator and a denominator. */
typedef struct {
  int os;  /* numerator */
  int nim; /* denominator */
} Murtoluku;

/* Reduces a fraction to its simplest form. */
Murtoluku supistettuML(int osoittaja, int nimittaja);

/* Prints a fraction in the form "numerator/denominator". */
void tulostaML(Murtoluku m);

/* Adds two fractions. */
Murtoluku lisaaML(Murtoluku a, Murtoluku b);

/* Subtracts the second fraction from the first. */
Murtoluku vahennaML(Murtoluku a, Murtoluku b);

/* Multiplies two fractions. */
Murtoluku kerroML(Murtoluku a, Murtoluku b);

/* Divides the first fraction by the second. */
Murtoluku jaaML(Murtoluku a, Murtoluku b);

#endif /* MURTOLUKU_H */
