#include "kortit.h"
#include <stdio.h>

const char *MAIDEN_NIMET[MAA_LKM + 1] = {
    "", "Hertta", "Risti", "Ruutu", "Pata",
};
const char *ARVOJEN_NIMET[MAA_KOKO + 1] = {
    "",       "ässä", "kakkonen", "kolmonen", "nelonen", "viitonen", "kuutonen",
    "seiska", "kasi", "ysi",      "kymppi",   "jätkä",   "rouva",    "kunkku"};

/* Concatenates the suit and rank names to print a card. */
void tulostaKortti(Kortti kortti) {
  printf("%s%s", MAIDEN_NIMET[kortti.maa], ARVOJEN_NIMET[kortti.arvo]);
}

/* Concatenates the suit and rank names to print a card using pointer access. */
void tulostaKorttiOs(Kortti *kortti) {
  printf("%s%s", MAIDEN_NIMET[kortti->maa], ARVOJEN_NIMET[kortti->arvo]);
}
