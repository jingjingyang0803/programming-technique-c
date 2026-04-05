#include "pvm.h"
#include <stdio.h>

int main(void) {
  Pvm a = {28, 2, 1900, "ke"};  /* Wednesday 28.2.1900 */
  Pvm b = {28, 2, 2016, "su"};  /* Sunday 28.2.2016 */
  Pvm c = {31, 12, 1960, "la"}; /* Saturday 31.12.1960 */
  printf("Pvm:n koko: %lu tavua\n",
         (unsigned long)sizeof(Pvm));           /* The size of a Pvm object. */
  printf("Päivämäärät ennen kasvattamista:\n"); /* The dates before incrementing
                                                   them with kasvataPvm. */
  tulostaPvm(&a); /* The parameter is a pointer to the Pvm object a, that is,
                     the address of a. */
  printf("\n");
  tulostaPvm(&b);
  printf("\n");
  tulostaPvm(&c);
  printf("\n");
  printf(
      "Päivämäärät kasvattamisen jälkeen:\n"); /* The dates after incrementing
                                                  them with kasvataPvm. */
  tulostaPvm(kasvataPvm(&a)); /* First increment and then print the result. */
  printf("\n");
  tulostaPvm(kasvataPvm(&b));
  printf("\n");
  tulostaPvm(kasvataPvm(&c));
  printf("\n");
  printf("Päivämäärien erot:\n"); /* The date differences (numbers of days
                                     between them). */
  tulostaPvm(&a);
  printf(" vs ");
  tulostaPvm(&b);
  printf(": %u\n", pvmEro(&a, &b));
  tulostaPvm(&b);
  printf(" vs ");
  tulostaPvm(&c);
  printf(": %u\n", pvmEro(&b, &c));
  tulostaPvm(&a);
  printf(" vs ");
  tulostaPvm(&c);
  printf(": %u\n", pvmEro(&a, &c));
  return 0;
}
