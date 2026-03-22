#ifndef CAESAR_H
#define CAESAR_H

/*
Encrypts the parameter string mj using the substitution table
described by the orig and perm parameters.
Here orig lists the characters of the original alphabet
and perm the characters of the permuted alphabet.
*/
void caesarKoodaa(char mj[], char orig[], char perm[]);

#endif /* CAESAR_H */