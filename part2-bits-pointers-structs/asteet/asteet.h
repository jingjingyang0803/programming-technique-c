/*
EXERCISE: Temperature
*/
#ifndef ASTEET_H
#define ASTEET_H

/* Defines three contants: Celsius, Fahrenheit and Kelvin */
typedef enum { Celsius, Fahrenheit, Kelvin } Asteikko;

/* Defines a temperature with a value and a scale */
typedef struct {
  float arvo;
  Asteikko asteikko;
} Lampotila;

/* Converts a temperature from one scale to another. */
float muunna(Lampotila a, Asteikko b);

/* Calculates the difference between two temperatures in a given scale. */
float erotus(Lampotila a, Lampotila b, Asteikko c);

#endif /* ASTEET_H */
