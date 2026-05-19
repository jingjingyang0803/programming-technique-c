/*
This program tests the pvm_ero function, which calculates the difference in days
between two dates. The function takes two strings as input, each representing a
date in the format "DD.MM.YYYY". The program calls the pvm_ero function with
different date pairs and prints the results.

Expected output:
    torstai 09.05.2013 --> tiistai 26.04.2016: yhteensä 1084 päivää
    Parametri "29.2.1900" tai "29.2.2000" on laiton!
    perjantai 05.08.2016 --> sunnuntai 21.08.2016: yhteensä 17 päivää
    Parametri "010.8.1957" tai "15.7.1930" on laiton!
*/
#include "pvm_ero.h"

int main(void) {
  pvm_ero("26.04.2016", "09.5.2013");
  pvm_ero("29.2.1900", "29.2.2000");
  pvm_ero("05.08.2016", "21.08.2016");
  pvm_ero("010.8.1957", "15.7.1930");

  return 0;
}
