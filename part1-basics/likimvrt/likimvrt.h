/* Functions for comparing double values with a specified tolerance */
#ifndef LIKIMVRT_H
#define LIKIMVRT_H


/* Returns the current value of the largest allowed discrepancy */
double lueToleranssi();

/* Changes the largest allowed discrepancy variable
   to have the value newTolerance */
void asetaToleranssi(double newTolerance);

/* Compares the parameters a and b for equality by checking if their values
   differ by at most the largest allowed discrepancy.
   Returns 1 if a and b are approximately equal and otherwise 0. */
int doubleVrt(double a, double b);


#endif /* LIKIMVRT_H */