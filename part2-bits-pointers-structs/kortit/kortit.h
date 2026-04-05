/*
EXERCISE: Cards
*/
#ifndef KORTIT_H
#define KORTIT_H

/* Defines the four suits. */
typedef enum { HERTTA = 1, RUUTU, RISTI, PATA } Maa;

/* Defines the thirteen ranks. */
typedef enum {
  ASSA = 1,
  KAKKONEN,
  KOLMONEN,
  NELONEN,
  VIITONEN,
  KUUTONEN,
  SEISKA,
  KASI,
  YSI,
  KYMPPI,
  JATKA,
  ROUVA,
  KUNKKU
} Arvo;

/* Number of suits, ranks and cards in a deck. */
enum { MAA_LKM = 4, MAA_KOKO = 13, KORTTI_LKM = MAA_LKM * MAA_KOKO };

/* Names of the suits and ranks for printing. */
extern const char *MAIDEN_NIMET[MAA_LKM + 1];
extern const char *KORTTIEN_NIMET[MAA_KOKO + 1];

/* Defines a card with a suit and a rank. */
typedef struct {
  Maa maa;
  Arvo arvo;
} Kortti;

/* Prints a string representation of a card using a value parameter. */
void tulostaKortti(Kortti kortti);

/* Prints a card using a pointer parameter. */
void tulostaKorttiOs(Kortti *kortti);

#endif /* KORTIT_H */
