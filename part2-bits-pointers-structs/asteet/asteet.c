/*
°F = °C · 1,8 + 32
°F = (K - 273,15) · 1,8 + 32
°C = (°F - 32) / 1,8
°C = K - 273,15
K = °C + 273,15
K = (°F - 32) / 1,8 + 273,15
*/
#include "asteet.h"

float muunna(Lampotila lampotila, Asteikko asteikko) {
  /* If the scales are the same, return the original value. */
  if (lampotila.asteikko == asteikko) {
    return lampotila.lampotila;
  }
  /* Convert the temperature to the desired scale. */
  if (lampotila.asteikko == Celsius) {
    if (asteikko == Fahrenheit) {
      return lampotila.lampotila * 1.8 + 32;
    } else if (asteikko == Kelvin) {
      return lampotila.lampotila + 273.15;
    }
  } else if (lampotila.asteikko == Fahrenheit) {
    if (asteikko == Celsius) {
      return (lampotila.lampotila - 32) / 1.8;
    } else if (asteikko == Kelvin) {
      return (lampotila.lampotila - 32) / 1.8 + 273.15;
    }
  } else if (lampotila.asteikko == Kelvin) {
    if (asteikko == Celsius) {
      return lampotila.lampotila - 273.15;
    } else if (asteikko == Fahrenheit) {
      return (lampotila.lampotila - 273.15) * 1.8 + 32;
    }
  }
  return -1; /* Invalid conversion */
}

float erotus(Lampotila a, Lampotila b, Asteikko asteikko) {
  float a_arvo = muunna(a, asteikko);
  float b_arvo = muunna(b, asteikko);
  return a_arvo - b_arvo;
}
