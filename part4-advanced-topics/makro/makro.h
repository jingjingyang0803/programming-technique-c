/*
EXERCISE: Macro definitions
Write a header file that defines the following macros:
- PII: A macro that represents the value of pi (3.141592653589793).
- MJ(x): A macro that takes a single argument x and converts it to a string
literal. For example, MJ(PII) should expand to "3.141592653589793".
- DESIMAALIT: A macro that defines the number of decimal places to use when
printing floating-point numbers. If DESIMAALIT is not defined, it should default
to 3.
- TYYPPI: A macro that defines the type to use for the variables s, t, u, and v
in the main function. If TYYPPI is not defined, it should default to unsigned
char.
- MIN(a, b): A macro that takes two arguments a and b and returns the smaller
of the two.
- MAX(a, b): A macro that takes two arguments a and b and returns the larger
of the two.
- MIN3(a, b, c): A macro that takes three arguments a, b,   and c and returns
the smallest of the three.
- MAX3(a, b, c): A macro that takes three arguments a, b, and c and returns
the largest of the three.
- MIN4(a, b, c, d): A macro that takes four arguments a, b, c, and d and returns
the smallest of the four.
- MAX4(a, b, c, d): A macro that takes four arguments a, b, c, and d and returns
the largest of the four.
- debug(msg): A macro that takes a single argument msg and prints it to the
standard error stream if the macro OTE_DEBUG is defined. If OTE_DEBUG is not
defined, the debug macro should do nothing.
*/
#ifndef MAKRO_H
#define MAKRO_H

#ifdef OTE_DEBUG
#include <stdio.h>
#endif

#define PII 3.141592653589793

#define MJ_APU(x) #x
#define MJ(x) MJ_APU(x)

#ifndef DESIMAALIT
#define DESIMAALIT 3
#endif

#ifndef TYYPPI
#define TYYPPI unsigned char
#endif

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN3(a, b, c) MIN(MIN((a), (b)), (c))
#define MAX3(a, b, c) MAX(MAX((a), (b)), (c))

#define MIN4(a, b, c, d) MIN(MIN3((a), (b), (c)), (d))
#define MAX4(a, b, c, d) MAX(MAX3((a), (b), (c)), (d))

#ifdef OTE_DEBUG
#define debug(msg) fprintf(stderr, msg)
#else
#define debug(msg)
#endif

#endif
