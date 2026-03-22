#include "likimvrt.h"
#include <math.h>
#include <stdio.h>

double toleranssi = 0.00000100000000000000;

double lueToleranssi() { return toleranssi; }

void asetaToleranssi(double newTolerance) { toleranssi = newTolerance; }

int doubleVrt(double a, double b) { return fabs(a - b) <= toleranssi; }
