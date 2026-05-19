/*
EXERCISE: String array #2
*/

#ifndef MJONOT_H
#define MJONOT_H

#include <stddef.h>

char **jarjesta_mjt(char **strs, size_t n,
                    int (*cmp)(const char *, const char *));

#endif
